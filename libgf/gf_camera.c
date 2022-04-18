#include <math.h>
#include "gf.h"
#include "gf_int.h"

/*
cam->x = gf_vec3(c[0] * c[1], s[0] * c[1], -s[1]);
cam->y = gf_vec3(c[0] * s[1] * s[2] - s[0] * c[2],
		s[0] * s[1] * s[2] + c[0] * c[2], c[1] * s[2]);
cam->z = gf_vec3(c[0] * s[1] * c[2] + s[0] * s[2],
		s[0] * s[1] * c[2] - c[0] * s[2], c[1] * c[2]);
In standarad yaw/pitch/roll definition, x axis is the direction axis.
We want z axis to be the direction axis - it's enough to rotate labels:
x -> z, y -> x, z -> y
Looking along z, x now points left and y points up.
Because screen coordinates are right/down oriented,
we need to additionally negate x and y axes
y -> -y, x -> -x
Be aware that we just redefine camera basis, but vectors of this basis
are still defined using absolute "world" basis.

To illustrate camera basis, let's take yaw = pitch = roll = 0. We get:
 << World basis >>  << Camera basis >>
    (absolute)            7 _
        _  ^             /  z
        z  |  7 _       /               
           | /  x      +------_->
           |/          |      x
  <--_-----+           | _
     y                 V y
*/
void	gf_camera_angle_changed(t_gf_camera *cam)
{
	double	s[3];
	double	c[3];

	s[0] = sin(cam->yaw);
	c[0] = cos(cam->yaw);
	s[1] = sin(cam->pitch);
	c[1] = cos(cam->pitch);
	s[2] = sin(cam->roll);
	c[2] = cos(cam->roll);
	cam->z = gf_vec3(c[0] * c[1], s[0] * c[1], -s[1]);
	cam->x = gf_vec3(-(c[0] * s[1] * s[2] - s[0] * c[2]),
			-(s[0] * s[1] * s[2] + c[0] * c[2]), -(c[1] * s[2]));
	cam->y = gf_vec3(-(c[0] * s[1] * c[2] + s[0] * s[2]),
			-(s[0] * s[1] * c[2] - c[0] * s[2]), -(c[1] * c[2]));
}

int	gf_project_rectilinear(t_gf_camera *cam, t_gf_point *pt, t_gf_vec3 v)
{
	t_gf_vec3	d;
	t_gf_vec3	r;
	double		norm;

	d = gf_vec3_sub(v, cam->pos);
	r.x = gf_vec3_dot(d, cam->x);
	r.y = gf_vec3_dot(d, cam->y);
	r.z = gf_vec3_dot(d, cam->z);
	if (r.z <= 0.)
		return (0);
	norm = cam->scale / (cam->fov * r.z);
	pt->x = gf_iround(r.x * norm) + cam->center.x;
	pt->y = gf_iround(r.y * norm) + cam->center.y;
	return (1);
}

int	gf_project_stereographic(t_gf_camera *cam, t_gf_point *pt, t_gf_vec3 v)
{
	t_gf_vec3	d;
	t_gf_vec3	r;
	double		norm;
	double		th;
	double		rp;

	d = gf_vec3_sub(v, cam->pos);
	r.x = gf_vec3_dot(d, cam->x);
	r.y = gf_vec3_dot(d, cam->y);
	r.z = gf_vec3_dot(d, cam->z);
	rp = sqrt(r.x * r.x + r.y * r.y);
	th = atan2(rp, r.z);
	norm = 2. * tan(th * 0.5) * cam->scale / (cam->fov * rp);
	pt->x = gf_iround(r.x * norm) + cam->center.x;
	pt->y = gf_iround(r.y * norm) + cam->center.y;
	return (1);
}

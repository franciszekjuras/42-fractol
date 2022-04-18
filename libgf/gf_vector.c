#include "gf.h"

t_gf_vec3	gf_vec3(double x, double y, double z)
{
	t_gf_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_gf_vec3	gf_vec3_neg(t_gf_vec3 v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}

t_gf_vec3	gf_vec3_sub(t_gf_vec3 v1, t_gf_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_gf_vec3	gf_vec3_add(t_gf_vec3 v1, t_gf_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_gf_vec3	gf_vec3_mult(t_gf_vec3 v, double m)
{
	v.x *= m;
	v.y *= m;
	v.z *= m;
	return (v);
}

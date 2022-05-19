/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:41:47 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:41:48 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GF_H
# define GF_H

# define GF_PI 3.14159265358979323846
# define GF_DEG 0.0174532925199432957692
# define GF_INVDEG 57.2957795130823208768

typedef struct s_gf_cplx
{
	double	re;
	double	im;
}	t_gf_cplx;

typedef struct s_gf_point
{
	int	x;
	int	y;
}	t_gf_point;

typedef struct s_gf_vec3
{
	double	x;
	double	y;
	double	z;
}	t_gf_vec3;

typedef struct s_gf_camera
{
	double		yaw;
	double		pitch;
	double		roll;
	t_gf_vec3	pos;
	t_gf_vec3	x;
	t_gf_vec3	y;
	t_gf_vec3	z;
	double		fov;
	double		scale;
	double		iso_dist;
	t_gf_point	center;
	int			(*project)(struct s_gf_camera *, t_gf_point *, t_gf_vec3);
}	t_gf_camera;

typedef struct s_gf_color
{
	int	b;
	int	g;
	int	r;
	int	a;
}	t_gf_color;

typedef struct s_gf_grad
{
	t_gf_color	beg;
	t_gf_color	end;
	double		va;
	double		vr;
	double		vg;
	double		vb;
	double		ibeg;
	double		iend;
}	t_gf_grad;

typedef struct s_gf_img
{
	void		*img;
	void		*adr;
	int			bypp;
	int			lnlen;
	int			endn;
	int			w;
	int			h;
	t_gf_point	pos;
	void		(*pxput)(struct s_gf_img *, t_gf_point, int);
}	t_gf_img;

typedef struct s_gf_ctx
{
	void		*mlx;
	void		*win;
	t_gf_img	img;
	int			w;
	int			h;
	int			do_repaint;
	void		*data;
}	t_gf_ctx;

/*gf_core.c*/
t_gf_point	gf_point(int x, int y);
t_gf_point	gf_point_add(t_gf_point a, t_gf_point b);
t_gf_point	gf_point_sub(t_gf_point a, t_gf_point b);
void		gf_point_put(t_gf_ctx *ctx, t_gf_point point, t_gf_color color);
/*gf_img.c*/
t_gf_img	gf_img(void *mlx, int w, int h);
void		gf_img_put(t_gf_ctx *ctx, t_gf_img *img);
void		gf_img_clear(t_gf_img *img);
/*gf_basics.c*/
void		gf_framebox_put(t_gf_ctx *ctx, t_gf_point pt_tl,
				t_gf_point pt_br, t_gf_color color);
/*gf_line.c*/
void		gf_line_put(t_gf_ctx *ctx,
				t_gf_point beg, t_gf_point end, t_gf_color color);
/*gf_lineclip.c*/
int			gf_lineclip(t_gf_img *img, t_gf_point *pt1, t_gf_point *pt2);
/*gf_color.c*/
int			gf_ctoi(t_gf_color color);
t_gf_color	gf_rgb(int r, int g, int b);
t_gf_color	gf_hsl(double h, double s, double l);
t_gf_color	gf_hsv(double h, double s, double v);
/*gf_grad.c*/
t_gf_grad	gf_grad(t_gf_color beg, t_gf_color end, double ibeg, double iend);
t_gf_color	gf_color_grad(double i, t_gf_grad *grad);
/*gf_vector.c*/
t_gf_vec3	gf_vec3(double x, double y, double z);
t_gf_vec3	gf_vec3_neg(t_gf_vec3 v);
t_gf_vec3	gf_vec3_sub(t_gf_vec3 v1, t_gf_vec3 v2);
t_gf_vec3	gf_vec3_add(t_gf_vec3 v1, t_gf_vec3 v2);
t_gf_vec3	gf_vec3_mult(t_gf_vec3 v, double m);
double		gf_vec3_dot(t_gf_vec3 v1, t_gf_vec3 v2);
t_gf_vec3	gf_vec3_cross(t_gf_vec3 v1, t_gf_vec3 v2);
double		gf_vec3_len(t_gf_vec3 v);
t_gf_vec3	gf_vec3_norm(t_gf_vec3 v);
void		gf_vec3_ineg(t_gf_vec3 *v);
void		gf_vec3_isub(t_gf_vec3 *v1, t_gf_vec3 v2);
void		gf_vec3_iadd(t_gf_vec3 *v1, t_gf_vec3 v2);
void		gf_vec3_imult(t_gf_vec3 *v, double m);
/*gf_camera.c*/
void		gf_camera_angle_changed(t_gf_camera *cam);
int			gf_project_rectilinear(t_gf_camera *cam,
				t_gf_point *pt, t_gf_vec3 v);
int			gf_project_stereographic(t_gf_camera *cam,
				t_gf_point *pt, t_gf_vec3 v);
#endif

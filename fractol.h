#ifndef FRACTOL_H
# define FRACTOL_H

# include <libgf/gf.h>
# include <libgf/cplx.h>

# define MAX_ITER 500
# define ZOOM_STEP 1.2

typedef struct s_data
{
	t_gf_point	center;
	t_cplx		pos;
	double		ppx;
	int			i;
	t_gf_point	focus;
	t_gf_point	move_start;
	int			maxit;
	double		*params;
	int			(*fractal)(t_cplx, int, double *);
	t_gf_color	(*color_fun)(int);
}	t_data;

int			render(t_gf_ctx *ctx);
int			close_app(t_gf_ctx *ctx);
t_cplx		pt_to_z(t_gf_point pt, t_data *data);
t_gf_color	color_fun(int it);
int			handle_key(int keycode, t_gf_ctx *ctx);
int			handle_mouse_release(int button, int x, int y, t_gf_ctx *ctx);
int			handle_mouse_move(int x, int y, t_gf_ctx *ctx);
int			handle_mouse_button(int button, int x, int y, t_gf_ctx *ctx);

#endif
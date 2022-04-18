#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <X11/X.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include <libgf/gf.h>
#include <libgf/cplx.h>
#include <libgf/gf_keys.h>
#include "fractol.h"

int	close_app(t_gf_ctx *ctx)
{
	(void) ctx;
	exit(0);
	return (0);
}

t_gf_color mandelbrot(t_cplx c, double *params)
{
	int		i;
	t_cplx	z;

	(void) params;
	i = -1;
	z = cplx(0, 0);
	while (++i < 100 && cplx_abs2(z) < 4.)
		z = cplx_add(cplx_square(z), c);
	if (i == 245)
		return (gf_rgb(0, 0, 0));
	return (gf_rgb(255 - i, 50, 50));
}

t_gf_color julia(t_cplx c, double *params)
{
	int		i;
	t_cplx	z;
	t_cplx	p;

	p = cplx(params[0], params[1]);
	i = -1;
	z = c;
	while (++i < 245 && cplx_abs2(z) < 4.)
		z = cplx_add(cplx_square(z), p);
	if (i == 245)
		return (gf_rgb(0, 0, 0));
	return (gf_rgb(255 - i, 50, 50));
}


t_cplx pt_to_z(t_gf_point pt, t_data *data)
{
	t_cplx	z;

	z.re = ((pt.x - data->center.x) * data->ppx);
	z.im = (-(pt.y - data->center.y) * data->ppx);
	cplx_iadd(&z, data->pos);
	return (z);
}

int	render(t_gf_ctx *ctx)
{
	t_data		*data;
	t_gf_point	pt;
	double		params[2];
	struct timespec time_crr;
	struct timespec time_prev;
	long			nanos;

	params[0] = -0.4;
	params[1] = 0.6;
	gf_img_clear(&ctx->img);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_prev);
	data = ctx->data;
	pt = gf_point(0, 0);
	while (pt.y < ctx->img.h)
	{
		pt.x = 0;
		while (pt.x < ctx->img.w)
		{
			gf_point_put(ctx, pt, julia(pt_to_z(pt, data), params));
			++pt.x;
		}
		++pt.y;
	}
	// do something time consuming
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_crr);
	nanos = (1000000000l * (time_crr.tv_sec - time_prev.tv_sec)
		+ (time_crr.tv_nsec - time_prev.tv_nsec));
	fprintf(stderr, "%ld\n", nanos/1000);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img.img, 0, 0);
	return (0);
}

int	handle_key(int keycode, t_gf_ctx *ctx)
{
	if (GF_K_ESC == keycode)
		close_app(ctx);
	fprintf(stderr, "Key presses: %d\n", keycode);
	render(ctx);
	return (0);
}

// int	handle_mouse(int keycode, t_gf_ctx *ctx)
// {
// 	fprintf(stderr, "Key presses: %d\n", keycode);
// 	render(ctx);
// 	return (0);
// }

// int	handle_mouse_button(int button,int x,int y, t_gf_ctx *ctx)
// {
// 	fprintf(stderr, "Mouse button %d at %dx%d.\n", button, x, y);
// 	if (button == 1)
// 		mlx_hook(ctx->win, MotionNotify, PointerMotionMask, 0, 0);
// 	return (0);
// }

// int	handle_mouse_move(int x,int y, t_gf_ctx *ctx)
// {
// 	(void) ctx;
// 	fprintf(stderr, "Mouse at %dx%d.\n",x,y);
// 	return (0);
// }

void	ctx_data_init(t_gf_ctx *ctx, t_data *data)
{
	ctx->data = data;
	data->center = gf_point(ctx->img.w / 2, ctx->img.h / 2);
	data->pos = cplx(0., 0.);
	data->ppx = 2. / data->center.x;
}

void	context_init(t_gf_ctx *ctx)
{
	ctx->mlx = mlx_init();
	ctx->w = 1600;
	ctx->h = 900;
	ctx->win = mlx_new_window(ctx->mlx, ctx->w, ctx->h, "Fractol");
	ctx->img = gf_img(ctx->mlx, ctx->w, ctx->h);
	ctx->do_repaint = 1;
	// mlx_hook(ctx->win, MotionNotify, PointerMotionMask, handle_mouse_move, ctx);
	// mlx_mouse_hook(ctx->win, handle_mouse_button, ctx);
	mlx_do_key_autorepeaton(ctx->mlx);
}

int	main(int argc, char **argv)
{
	t_gf_ctx	ctx;
	t_data		data;

	(void) argc;
	(void) argv;
	context_init(&ctx);
	ctx_data_init(&ctx, &data);
	mlx_hook(ctx.win, DestroyNotify, 0, &close_app, &ctx);
	mlx_hook(ctx.win, KeyPress, KeyPressMask, &handle_key, &ctx);
	render(&ctx);
	mlx_loop(ctx.mlx);
}

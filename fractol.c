#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include <libgf/cplx.h>
#include <libgf/gf.h>
#include <libgf/gf_keys.h>
#include "fractals.h"
#include "fractol.h"

int	handle_key(int keycode, t_gf_ctx *ctx)
{
	if (GF_K_ESC == keycode)
		close_app(ctx);
	fprintf(stderr, "Key press: %d\n", keycode);
	ctx->do_repaint = 1;
	mlx_loop_hook(ctx->mlx, render, ctx);
	return (0);
}

int	handle_mouse_button(int button, int x, int y, t_gf_ctx *ctx)
{
	t_data	*data;

	data = ctx->data;
	if (button == GF_M_SCRLUP || button == GF_M_SCRLDN)
	{
		data->focus = gf_point(x, y);
		data->pos = pt_to_z(data->focus, data);
		if (button == GF_M_SCRLUP)
			data->ppx /= ZOOM_STEP;
		else
			data->ppx *= ZOOM_STEP;
		cplx_iadd(&data->pos,
			cplx_sub(data->pos, pt_to_z(gf_point(x, y), data)));
	}
	ctx->do_repaint = 1;
	mlx_loop_hook(ctx->mlx, render, ctx);
	return (0);
}

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
	data->focus = data->center;
	data->pos = cplx(0., 0.);
	data->ppx = 2. / data->center.x;
	data->params = ft_calloc(2, sizeof(double));
	data->params[0] = -0.4;
	data->params[1] = 0.6;
	data->fractal = julia;
	data->color_fun = color_fun;
	data->maxit = MAX_ITER;
}

// mlx_hook(ctx->win, MotionNotify, PointerMotionMask, handle_mouse_move, ctx);
void	context_init(t_gf_ctx *ctx)
{
	ctx->mlx = mlx_init();
	ctx->w = 800;
	ctx->h = 600;
	ctx->win = mlx_new_window(ctx->mlx, ctx->w, ctx->h, "Fractol");
	ctx->img = gf_img(ctx->mlx, ctx->w, ctx->h);
	ctx->do_repaint = 1;
	mlx_mouse_hook(ctx->win, handle_mouse_button, ctx);
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
	mlx_loop_hook(ctx.mlx, render, &ctx);
	mlx_loop(ctx.mlx);
}

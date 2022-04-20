#include <stdlib.h>
#include <X11/X.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include <libgf/cplx.h>
#include <libgf/gf.h>
#include <libgf/gf_keys.h>
#include "fractol.h"

int	handle_key(int keycode, t_gf_ctx *ctx)
{
	if (GF_K_ESC == keycode)
		close_app(ctx);
	ctx->do_repaint = 1;
	mlx_loop_hook(ctx->mlx, render, ctx);
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_gf_ctx *ctx)
{
	t_gf_point	diff;
	t_data		*data;

	data = ctx->data;
	if (button == GF_M_LEFT)
	{
		mlx_hook(ctx->win, MotionNotify, PointerMotionMask, 0, 0);
		ctx->img.pos = gf_point(0, 0);
		diff = gf_point_sub(data->move_start, gf_point(x, y));
		cplx_iadd(&data->pos, cplx(diff.x * data->ppx, -diff.y * data->ppx));
		data->focus = data->center;
		gf_img_clear(&ctx->img);
		ctx->do_repaint = 1;
		mlx_loop_hook(ctx->mlx, render, ctx);
	}
	return (0);
}

int	handle_mouse_move(int x, int y, t_gf_ctx *ctx)
{
	t_gf_point	diff;
	t_data		*data;

	data = ctx->data;
	diff = gf_point_sub(gf_point(x, y), data->move_start);
	ctx->img.pos = diff;
	gf_img_put(ctx, &ctx->img);
	return (0);
}

int	handle_mouse_button(int button, int x, int y, t_gf_ctx *ctx)
{
	t_data	*data;

	data = ctx->data;
	if (button == GF_M_LEFT)
	{
		data->move_start = gf_point(x, y);
		mlx_hook(ctx->win, MotionNotify, PointerMotionMask,
			handle_mouse_move, ctx);
	}
	else if (button == GF_M_SCRLUP || button == GF_M_SCRLDN)
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

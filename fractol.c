/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:30 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/22 11:40:11 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include <libgf/cplx.h>
#include <libgf/gf.h>
#include "fractals.h"
#include "fractol.h"

// typedef struct s_ft_argparse
// {
// 	char	arg;
// 	char	count;
// 	char	**params;
// }	t_ft_argparse;

static void ctx_data_init_fractal(t_data *data, t_ft_argparse *arg)
{
	if (arg == NULL || arg->count == 0)
		print_help_exit(1);
	(void) data;
}

static void	ctx_data_init(t_gf_ctx *ctx, t_data *data, t_ft_argparse *args)
{
	ctx->data = data;
	ctx_data_init_fractal(data, ft_argparse_find(args, '-'));
	data->center = gf_point(ctx->img.w / 2, ctx->img.h / 2);
	data->focus = data->center;
	data->pos = cplx(0., 0.);
	data->ppx = 2. / data->center.x;
	data->params = ft_calloc(2, sizeof(double));
	data->params[0] = -0.4;
	data->params[1] = 0.6;
	// data->fractal = burning_ship;
	data->color_fun = color_fun;
	data->maxit = MAX_ITER;
}

static void	context_init(t_gf_ctx *ctx)
{
	ctx->mlx = mlx_init();
	ctx->w = 1000;
	ctx->h = 700;
	ctx->win = mlx_new_window(ctx->mlx, ctx->w, ctx->h, "Fractol");
	ctx->img = gf_img(ctx->mlx, ctx->w, ctx->h);
	ctx->do_repaint = 1;
	mlx_mouse_hook(ctx->win, handle_mouse_button, ctx);
	mlx_hook(ctx->win, ButtonRelease, ButtonReleaseMask,
		handle_mouse_release, ctx);
	mlx_hook(ctx->win, MotionNotify, PointerMotionMask, 0, 0);
	mlx_do_key_autorepeaton(ctx->mlx);
}

int	main(int argc, char **argv)
{
	t_gf_ctx		ctx;
	t_data			data;
	t_ft_argparse	*args;

	print_help_exit(0);
	args = ft_argparse(argc, argv);	
	context_init(&ctx);
	ctx_data_init(&ctx, &data, args);
	mlx_hook(ctx.win, DestroyNotify, 0, &close_app, &ctx);
	mlx_hook(ctx.win, KeyPress, KeyPressMask, &handle_key, &ctx);
	mlx_loop_hook(ctx.mlx, render, &ctx);
	mlx_loop(ctx.mlx);
}

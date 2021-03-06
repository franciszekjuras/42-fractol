/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:01 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:38:02 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx/mlx.h>
#include <libft/libft.h>
#include <libgf/gf.h>
#include "fractol.h"

static void	fractal_point_put(t_gf_ctx *ctx, t_gf_point pt)
{
	t_data		*data;
	int			it;
	t_gf_color	color;

	data = ctx->data;
	it = data->fractal(pt_to_z(pt, data), data->maxit, data->params);
	if (it == data->maxit)
		color = gf_rgb(0, 0, 0);
	else
		color = data->color_fun(it);
	gf_point_put(ctx, pt, color);
}

static int	render_lr(t_gf_ctx *ctx, t_gf_point rng[2])
{
	int			limit;
	int			pixels;
	t_gf_point	pt;

	pixels = 0;
	limit = ft_min(rng[1].y, ctx->img.h - 1);
	pt = gf_point(rng[0].x, ft_max(rng[0].y, 0) - 1);
	if (rng[0].x >= 0)
	{
		pixels += limit - pt.y;
		while (++pt.y <= limit)
			fractal_point_put(ctx, pt);
	}
	pt = gf_point(rng[1].x, ft_max(rng[0].y, 0) - 1);
	if (rng[1].x < ctx->img.w)
	{
		pixels += limit - pt.y;
		while (++pt.y <= limit)
			fractal_point_put(ctx, pt);
	}
	return (pixels);
}

static int	render_tb(t_gf_ctx *ctx, t_gf_point rng[2])
{
	int			limit;
	int			pixels;
	t_gf_point	pt;

	pixels = 0;
	limit = ft_min(rng[1].x, ctx->img.w);
	pt = gf_point(ft_max(rng[0].x, 0), rng[0].y);
	if (rng[0].y >= 0)
	{
		pixels += ft_max(0, limit - pt.x - 1);
		while (++pt.x < limit)
			fractal_point_put(ctx, pt);
	}
	pt = gf_point(ft_max(rng[0].x, 0), rng[1].y);
	if (rng[1].y < ctx->img.h)
	{
		pixels += ft_max(0, limit - pt.x - 1);
		while (++pt.x < limit)
			fractal_point_put(ctx, pt);
	}
	return (pixels);
}

static int	render_next_square(t_gf_ctx *ctx, t_data *data)
{
	t_gf_point	rng[2];
	int			pixels_limit;
	int			pixels_current;
	int			pixels_sum;

	pixels_sum = 0;
	pixels_current = -1;
	pixels_limit = 5000 + data->i * 100;
	while (pixels_sum < pixels_limit && pixels_current != 0)
	{
		rng[0] = gf_point_add(data->focus, gf_point(-data->i, -data->i));
		rng[1] = gf_point_add(data->focus, gf_point(data->i, data->i));
		pixels_current = render_lr(ctx, rng);
		pixels_current += render_tb(ctx, rng);
		pixels_sum += pixels_current;
		++data->i;
	}
	return (pixels_current == 0);
}

int	render(t_gf_ctx *ctx)
{
	t_data		*data;
	int			finished;

	data = ctx->data;
	if (ctx->do_repaint)
		data->i = 0;
	ctx->do_repaint = 0;
	finished = render_next_square(ctx, data);
	gf_img_put(ctx, &ctx->img);
	if (finished)
		mlx_loop_hook(ctx->mlx, 0, 0);
	return (0);
}

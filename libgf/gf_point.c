/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:41:20 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:41:21 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx/mlx.h>
#include "gf.h"
#include "gf_int.h"

t_gf_point	gf_point(int x, int y)
{
	t_gf_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_gf_point	gf_point_add(t_gf_point a, t_gf_point b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_gf_point	gf_point_sub(t_gf_point a, t_gf_point b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

void	gf_point_put(t_gf_ctx *ctx, t_gf_point point, t_gf_color color)
{
	ctx->img.pxput(&ctx->img, point,
		mlx_get_color_value(ctx->mlx, gf_ctoi(color)));
}

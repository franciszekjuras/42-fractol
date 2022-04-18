#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include "gf.h"
#include "gf_int.h"


// static void	gf_line_put_x(
// 	t_gf_ctx *ctx, t_gf_point beg, t_gf_point end, int good_color)
// {
// 	double		a;
// 	int			x;
// 	t_gf_point	pt;

// 	a = (double)(end.y - beg.y) / (end.x - beg.x);
// 	x = beg.x;
// 	while (x < end.x)
// 	{
// 		pt.x = x;
// 		pt.y = beg.y + ((int)(a * (x - beg.x)));
// 		ctx->img.pxput(&ctx->img, pt, good_color);
// 		++x;
// 	}
// }

// static void	gf_line_put_y(
// 	t_gf_ctx *ctx, t_gf_point beg, t_gf_point end, int good_color)
// {
// 	double		a;
// 	int			y;
// 	t_gf_point	pt;

// 	a = (double)(end.x - beg.x) / (end.y - beg.y);
// 	y = beg.y;
// 	while (y < end.y)
// 	{
// 		pt.y = y;
// 		pt.x = beg.x + ((int)(a * (y - beg.y)));
// 		ctx->img.pxput(&ctx->img, pt, good_color);
// 		++y;
// 	}
// }

static void	gf_line_put_x(
	t_gf_ctx *ctx, t_gf_point beg, t_gf_point end, int good_color)
{
	t_gf_point	d;
	int			e;
	int			yi;

	d.x = end.x - beg.x;
	d.y = end.y - beg.y;
	yi = 1;
	if (d.y < 0)
	{
		yi = -1;
		d.y = -d.y;
	}
	e = 2 * d.y - d.x;
	while (beg.x < end.x)
	{
		ctx->img.pxput(&ctx->img, beg, good_color);
		if (e > 0)
		{
			beg.y += yi;
			e += 2 * d.y - 2 * d.x;
		}
		else
			e += 2 * d.y;
		beg.x += 1;
	}
}

static void	gf_line_put_y(
	t_gf_ctx *ctx, t_gf_point beg, t_gf_point end, int good_color)
{
	t_gf_point	d;
	int			e;
	int			xi;

	d.x = end.x - beg.x;
	d.y = end.y - beg.y;
	xi = 1;
	if (d.x < 0)
	{
		xi = -1;
		d.x = -d.x;
	}
	e = 2 * d.x - d.y;
	while (beg.y < end.y)
	{
		ctx->img.pxput(&ctx->img, beg, good_color);
		if (e > 0)
		{
			beg.x += xi;
			e += 2 * d.x - 2 * d.y;
		}
		else
			e += 2 * d.x;
		beg.y += 1;
	}
}

void	gf_line_put(
	t_gf_ctx *ctx, t_gf_point p1, t_gf_point p2, t_gf_color color)
{
	int	good_color;

	if (!gf_lineclip(&ctx->img, &p1, &p2))
		return ;
	good_color = mlx_get_color_value(ctx->mlx, gf_ctoi(color));
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
	{
		if (p2.x > p1.x)
			gf_line_put_x(ctx, p1, p2, good_color);
		else
			gf_line_put_x(ctx, p2, p1, good_color);
	}
	else
	{
		if (p2.y > p1.y)
			gf_line_put_y(ctx, p1, p2, good_color);
		else
			gf_line_put_y(ctx, p2, p1, good_color);
	}
}

// void	gf_line_put(
// 	t_gf_ctx* ctx, t_gf_point beg, t_gf_point end, t_gf_color color)
// {
// 	t_gf_point	d;
// 	int			e2;
// 	int			e;
// 	int			good_color;
// 	t_gf_point	s;

// 	d.x = abs(end.x - beg.x);
// 	s.x = beg.x < end.x ? 1 : -1;
// 	d.y = -abs(end.y - beg.y);
// 	s.y = beg.y < end.y ? 1 : -1;
// 	e = 2 * (d.x + d.y);
// 	good_color = mlx_get_color_value(ctx->mlx, gf_ctoi(color));
// 	while (1)
// 	{
// 		ctx->img.pxput(&ctx->img, beg, good_color);
// 		if (beg.x == end.x && beg.y == end.y)
// 			break;
// 		e2 = 2 * e;
// 		if (e2 >= d.y)
// 		{
// 			if (beg.x == end.x)
// 				break;
// 			e += d.y;
// 			beg.x += s.x;
// 		}
// 		else if (e2 <= d.x)
// 		{
// 			if (beg.y == end.y)
// 				break;
// 			e += d.x;
// 			beg.y += s.y;
// 		}
// 	}
// }

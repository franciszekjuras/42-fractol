#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mlx/mlx.h>
#include "gf.h"
#include "gf_int.h"

// static void	gf_point_put_stat(t_gf_ctx* ctx, t_gf_point point, int color)
// {
// 	// mlx_pixel_put(ctx->mlx, ctx->win, point.x, point.y, gf_ctoi(color));
// 	ctx->img.pxput(&ctx->img, point,
// 		color);
// }

void	gf_framebox_put(
	t_gf_ctx *ctx, t_gf_point pt_tl, t_gf_point pt_br, t_gf_color color)
{
	t_gf_point	pt;
	int			good_color;

	if (!(gf_inimage(&ctx->img, &pt_tl) && gf_inimage(&ctx->img, &pt_br)))
		return ;
	good_color = mlx_get_color_value(ctx->mlx, gf_ctoi(color));
	pt = pt_tl;
	while (pt.x <= pt_br.x)
	{
		while (pt.y <= pt_br.y)
		{
			ctx->img.pxput(&ctx->img, pt, good_color);
			pt.y++;
		}
		pt.y = pt_tl.y;
		pt.x++;
	}
}

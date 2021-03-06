/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:40:47 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/23 20:17:22 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx/mlx.h>
#include <libft/libft.h>
#include "gf.h"
#include "gf_int.h"

t_gf_img	gf_img(void *mlx, int w, int h)
{
	t_gf_img	img;
	int			bitspp;

	img.img = mlx_new_image(mlx, w, h);
	img.w = w;
	img.h = h;
	img.pos = gf_point(0, 0);
	img.adr = mlx_get_data_addr(img.img, &bitspp, &img.lnlen, &img.endn);
	img.bypp = bitspp / 8;
	if (img.bypp == 4)
		img.pxput = gf_int_img_pxput4;
	else
	{
		ft_dprintf(2, "Error: Unsupported pixel width %d\n", img.bypp);
		exit(1);
	}
	return (img);
}

void	gf_img_put(t_gf_ctx *ctx, t_gf_img *img)
{
	mlx_put_image_to_window(ctx->mlx, ctx->win, img->img,
		img->pos.x, img->pos.y);
}

void	gf_img_clear(t_gf_img *img)
{	
	ft_bzero(img->adr, img->lnlen * img->h);
}

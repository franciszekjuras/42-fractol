/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_int_pxput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:40:51 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:40:52 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gf.h"

void	gf_int_img_pxput4(t_gf_img *img, t_gf_point pt, int good_color)
{
	int	*adr;

	adr = img->adr + img->lnlen * pt.y;
	adr += pt.x;
	*adr = good_color;
}

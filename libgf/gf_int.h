/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:41:03 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:41:03 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GF_INT_H
# define GF_INT_H

# include "gf.h"

# define GF_T 1
# define GF_B 2
# define GF_L 4
# define GF_R 8

void		gf_int_img_pxput4(t_gf_img *img, t_gf_point pt, int good_color);
int			gf_iround(double v);
int			gf_inimage(t_gf_img *img, t_gf_point *pt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:10 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/22 11:47:49 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <libft/libft.h>
#include <libgf/gf.h>
#include "fractol.h"

void	print_help_exit(int status)
{
	ft_putendl_fd("Usage: fractol <fractal> [parameters] [options]\n"
	"Supported fractals:\n"
	"	mandelbrot\n"
	"	julia <real part> <imaginary part>\n"
	"	\"burning ship\" | ship\n"
	"Options:\n"
	"	-s <width> <height> window size in pixels\n"
	"	-i <max iterations> maximal number of iterations when rendering"
	, 1);
	exit(status);
}

int	close_app(t_gf_ctx *ctx)
{
	(void) ctx;
	exit(0);
	return (0);
}

t_cplx	pt_to_z(t_gf_point pt, t_data *data)
{
	t_cplx	z;

	z.re = ((pt.x - data->center.x) * data->ppx);
	z.im = (-(pt.y - data->center.y) * data->ppx);
	cplx_iadd(&z, data->pos);
	return (z);
}

t_gf_color	color_fun(int it)
{
	double	t;

	t = 0.08 * it;
	t = log10(t + 10.);
	return (gf_hsl(t, 0.8, 0.5 + 0.2 * cos(6 * t)));
}

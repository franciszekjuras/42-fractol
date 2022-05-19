/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:50 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:38:51 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cplx.h"

t_cplx	cplx(double re, double im)
{
	t_cplx	v;

	v.re = re;
	v.im = im;
	return (v);
}

t_cplx	cplx_add(t_cplx a, t_cplx b)
{
	a.re += b.re;
	a.im += b.im;
	return (a);
}

t_cplx	cplx_sub(t_cplx a, t_cplx b)
{
	a.re -= b.re;
	a.im -= b.im;
	return (a);
}

t_cplx	cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx	v;

	v.re = a.re * b.re - a.im * b.im;
	v.im = a.re * b.im + a.im * b.re;
	return (v);
}

t_cplx	cplx_scale(t_cplx a, double s)
{
	a.re *= s;
	a.im *= s;
	return (a);
}

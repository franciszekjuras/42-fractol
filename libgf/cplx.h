/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:57 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:38:58 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPLX_H
# define CPLX_H

typedef struct s_cplx
{
	double	re;
	double	im;
}	t_cplx;

t_cplx	cplx(double re, double im);
t_cplx	cplx_add(t_cplx a, t_cplx b);
t_cplx	cplx_sub(t_cplx a, t_cplx b);
t_cplx	cplx_mult(t_cplx a, t_cplx b);
t_cplx	cplx_scale(t_cplx a, double s);
t_cplx	cplx_square(t_cplx a);
t_cplx	cplx_conj(t_cplx a);
double	cplx_abs2(t_cplx a);
void	cplx_iadd(t_cplx *a, t_cplx b);
void	cplx_isub(t_cplx *a, t_cplx b);
void	cplx_iscale(t_cplx *a, double s);

#endif

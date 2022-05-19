/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:37 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/19 20:38:38 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

int	mandelbrot(t_cplx c, int maxit, double *params);
int	julia(t_cplx c, int maxit, double *params);
int	burning_ship(t_cplx c, int maxit, double *params);

#endif
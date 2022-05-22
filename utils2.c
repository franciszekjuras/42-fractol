/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:10 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/22 13:03:11 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <libft/libft.h>
#include <libgf/gf.h>
// #include "fractol.h"

void	parse_fractal_params(double *arr, char **params, int num, char *fractal)
{
	int		i;
	char	*param;

	i = 0;
	while (i < num && params[i] != NULL)
	{
		param = params[i];
		arr[i] = gf_strtodouble(&param);
		if (isnan(arr[i]) || *param != '\0')
			break ;
		++i;
	}
	if (i != num)
	{
		ft_dprintf(2, "Fractal %s requires %d valid parameters, got only %d\n",
			fractal, num, i);
		exit(1);
	}
}

void	parse_integer_params(int *arr, t_ft_argparse *arg, int num)
{
	int		i;
	int		err;
	char	*param;

	i = 0;
	while (i < num && arg->params[i] != NULL)
	{
		param = arg->params[i];
		arr[i] = ft_strtonum(&param, INT_MIN, INT_MAX, &err);
		if (err || *param != '\0')
			break ;
		++i;
	}
	if (i != num)
	{
		ft_dprintf(2, "Argument -%c requires %d valid parameters, got only %d\n",
			arg->arg, num, i);
		exit(1);
	}
}

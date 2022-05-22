/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gf_strtodouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:25:43 by fjuras            #+#    #+#             */
/*   Updated: 2022/05/22 11:15:36 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft/libft.h>

double	gf_strtodouble(char **npp)
{
	long long	base;
	int			pow10;
	int			err;

	err = 0;
	*npp = ft_strtofp(*npp, &base, &pow10, &err);
	if (err)
		return (NAN);
	return ((double) base * pow(10., pow10));
}

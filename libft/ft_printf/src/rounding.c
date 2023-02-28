/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:44:44 by abackman          #+#    #+#             */
/*   Updated: 2022/04/28 14:21:24 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Simplified banker's rounding for floats. Rounds to the nearest, ties to even.
*/

long double	ftoa_rounding(int prec, long double num)
{
	long double		pow;
	long double		tmp;
	int				i;
	int				nprec;

	i = 0;
	pow = 1.0;
	if (prec == -1)
		nprec = 6;
	else
		nprec = prec;
	if (prec == 0)
	{
		nprec = 1;
		pow /= 10;
	}
	while (i++ < nprec)
		pow *= 10;
	tmp = num;
	tmp *= pow;
	if ((unsigned long long)tmp % 2 == 0 && tmp - (unsigned long long)tmp \
	== 0.5)
		return (num);
	else
		return (num + 0.5 / pow);
}

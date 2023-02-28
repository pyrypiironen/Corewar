/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:28:13 by abackman          #+#    #+#             */
/*   Updated: 2022/04/25 12:32:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	signed_length_mod(t_print *p)
{
	long long	i;

	i = 0;
	if (p->l > 1)
		i = (long long int)va_arg(p->ap, long long int);
	else if (p->l == 1)
		i = (long int)va_arg(p->ap, long int);
	else if (p->h == 1)
		i = (short int)va_arg(p->ap, int);
	else if (p->h > 1)
		i = (signed char)va_arg(p->ap, int);
	else
		i = (int)va_arg(p->ap, int);
	return (i);
}

unsigned long long	unsigned_length_mod(t_print *p)
{
	unsigned long long	i;

	i = 0;
	if (p->l == 1 || p->z)
		i = (unsigned long)va_arg(p->ap, unsigned long);
	else if (p->l > 1)
		i = (unsigned long long)va_arg(p->ap, unsigned long long);
	else if (p->h == 1)
		i = (unsigned short)va_arg(p->ap, int);
	else if (p->h > 1)
		i = (unsigned char)va_arg(p->ap, int);
	else
		i = (unsigned int)va_arg(p->ap, unsigned int);
	return (i);
}

long double	float_length_mod(t_print *p)
{
	long double	num;

	num = 0;
	if (p->cap_l)
		num = (long double)va_arg(p->ap, long double);
	else
		num = (double)va_arg(p->ap, double);
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specifiers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:57:06 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/22 19:57:07 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	modifiers(const char *format, t_struct *d)
{
	if (format[d->pos] == 'h' && format[d->pos + 1] == 'h')
	{
		d->mod_hh = 1;
		d->pos = d->pos + 2;
	}
	else if (format[d->pos] == 'l' && format[d->pos + 1] == 'l')
	{
		d->mod_ll = 1;
		d->pos = d->pos + 2;
	}
	else if (format[d->pos] == 'h')
	{
		d->mod_h = 1;
		d->pos++;
	}
	else if (format[d->pos] == 'l')
	{
		d->mod_l = 1;
		d->pos++;
	}
	else if (format[d->pos] == 'L')
	{
		d->mod_big_l = 1;
		d->pos++;
	}
}

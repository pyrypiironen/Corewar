/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:57:04 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/20 14:57:07 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags(const char *format, t_struct *d)
{
	while (ft_strchr(FLAGS, format[d->pos]) != NULL)
	{
		if (format[d->pos] == '#')
			d->hash = 1;
		else if (format[d->pos] == '0')
			d->zero = 1;
		else if (format[d->pos] == '-')
			d->minus = 1;
		else if (format[d->pos] == '+')
			d->plus = 1;
		else if (format[d->pos] == ' ')
			d->space = 1;
		d->pos++;
	}
	if (d->plus == 1)
		d->space = 0;
}

void	width(const char *format, va_list ap, t_struct *d)
{
	int		i;

	i = width_numbers(format, d);
	if (i == 0)
	{
		if (format[d->pos] == '*')
		{
			d->width = va_arg(ap, int);
			if (d->width < 0)
			{
				d->width *= -1;
				d->minus = 1;
			}
				d->pos++;
		}
	}
	width_numbers(format, d);
}

int	width_numbers(const char *format, t_struct *d)
{
	int		i;
	char	str[20];

	i = 0;
	while (ft_strchr("0123456789", format[d->pos]) != NULL)
	{
		str[i] = format[d->pos];
		i++;
		d->pos++;
	}
	str[i] = '\0';
	if (i > 0)
		d->width = ft_atoi(str);
	return (i);
}

void	precision(const char *format, va_list ap, t_struct *d)
{
	int		i;
	char	str[20];

	i = 0;
	if (format[d->pos] == '.')
	{
		d->pos++;
		while (ft_strchr("0123456789", format[d->pos]) != NULL)
			str[i++] = format[d->pos++];
		if (i == 0)
			precision_asterix_check(format, ap, d);
		str[i] = '\0';
		if (i > 0)
			d->padding = ft_atoi(str);
		else if (d->padding == -1)
			d->padding = 0;
	}
}

void	precision_asterix_check(const char *format, va_list ap, t_struct *d)
{
	if (format[d->pos] == '*')
	{
		d->padding = va_arg(ap, int);
		d->pos++;
		if (d->padding < 0)
		{
			d->padding = -2;
			d->s_pad = -1;
			d->asterix = 1;
		}
	}
}

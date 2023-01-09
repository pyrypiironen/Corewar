/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:24:13 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/07 15:24:15 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*data;
	int			ret;

	if ((format[0] == '%' && format[1] == '\0') || format[0] == '\0')
		return (0);
	data = (t_struct *)malloc(sizeof(t_struct));
	if (data == NULL)
		return (-1);
	set_struct(data);
	if (format[0] == '{')
		read_color(format, data);
	va_start(ap, format);
	ret = read_format(format, ap, data);
	va_end(ap);
	free(data);
	return (ret);
}

int	read_format(const char *format, va_list ap, t_struct *d)
{
	while (format[d->pos] != '\0')
	{
		if (format[d->pos] != '%')
		{
			if (d->ppos >= 420)
			{
				write(1, &d->print, d->ppos);
				d->ppos = 0;
			}
			d->print[d->ppos] = format[d->pos];
			d->ppos++;
			d->res++;
		}
		else
			check_conversion(format, ap, d);
		d->pos++;
	}
	print_it(d);
	return (d->res);
}

void	check_conversion(const char *format, va_list ap, t_struct *d)
{
	d->pos++;
	if (is_conversion(format, d) == 1)
	{
		flags(format, d);
		width(format, ap, d);
		precision(format, ap, d);
		modifiers(format, d);
		conversion(format, ap, d);
		reset_struct(d);
	}
	else
		d->pos--;
}

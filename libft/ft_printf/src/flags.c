/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/07/07 12:22:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Functions that parse through the format string and stores data about them
** in the t_print struct.
*/

static int	width_helper(const char *format, t_print *p)
{
	int	width;

	width = 0;
	while (ft_strchr_int("0+- #*", format[p->i]))
	{
		if (format[p->i] == '0')
		{
			p->zero = 1;
			p->fl_zero = 1;
		}
		else if (format[p->i] == '+')
			p->plus = 1;
		else if (format[p->i] == '-')
			p->minus = 1;
		else if (format[p->i] == ' ')
			p->space = 1;
		else if (format[p->i] == '#')
			p->hash = 1;
		else if (format[p->i] == '*')
			width = va_arg(p->ap, int);
		p->i++;
	}
	return (width);
}

/*
** If width is specified through the '*' (an argument),
** this will be the width. The exception is if width is specified in the
** format string, the one with the smallest absolute value will be the width.
*/

static void	get_width(const char *format, t_print *p)
{
	int	new_width;

	new_width = 0;
	new_width = width_helper(format, p);
	if (new_width < 0)
	{
		p->minus = 1;
		p->w_save = 1;
		new_width *= -1;
	}
	while (ft_isdigit((int)format[p->i]))
		p->width = (p->width * 10) + (format[p->i++] - '0');
	if (new_width && !p->width)
		p->width = new_width;
	if (new_width && p->width && new_width < p->width)
		p->width = new_width;
}

static void	get_prec(const char *format, t_print *p, int save)
{
	p->check_neg = 0;
	if (format[p->i] != '.')
		return ;
	else
		p->precision = 0;
	if (format[++p->i] == '*')
	{
		save = va_arg(p->ap, int);
		p->i++;
	}
	if (format[p->i] == '-' || save < 0)
		p->check_neg = 1;
	if (format[p->i] == '-')
		p->i++;
	if (save < 0)
		save *= -1;
	while (ft_isdigit(format[p->i]))
		p->precision = (p->precision * 10) + (format[p->i++] - '0');
	p->p_save = save;
	if (save && (!p->check_neg || !p->precision))
		p->precision = save;
	else if (p->check_neg && !save)
		p->precision = 0;
}

static void	get_length(const char *format, t_print *p)
{
	while (ft_strchr_int("hlLz", format[p->i]) && format[p->i])
	{
		if (format[p->i] == 'h')
			p->h++;
		else if (format[p->i] == 'l')
			p->l++;
		else if (format[p->i] == 'L')
			p->cap_l++;
		else if (format[p->i] == 'z')
			p->z++;
		p->i++;
	}
}

int	get_field(const char *format, t_print *print)
{	
	int	save;

	save = 0;
	get_width(format, print);
	while (format[print->i] && format[print->i] == '*')
		print->i++;
	get_prec(format, print, save);
	if (print->minus && !print->w_save && !print->p_save)
		print->zero = 0;
	else if (print->precision > 0 && print->zero)
		print->zero = 0;
	get_length(format, print);
	return (0);
}

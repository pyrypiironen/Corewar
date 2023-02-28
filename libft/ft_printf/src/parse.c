/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:30:20 by abackman          #+#    #+#             */
/*   Updated: 2023/02/28 13:29:28 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_conversion(t_print *p, int bytes)
{
	if (p->conv == 'c')
		p->ret += write(p->fd, p->str, bytes);
	else
		p->ret += write(p->fd, p->str, (size_t)ft_strlen_int(p->str));
	ft_strdel(&p->str);
}

/*
** Called when a valid flag or conversion specifier is found. Parses through
** the format string, stores information about flags and specifiers in the
** t_print struct and then performs the conversion, if given a valid specifier.
*/

int	convert_yes(t_print *print, const char *format)
{
	int	x;
	int	ret;

	x = 0;
	ret = 0;
	init_struct(print);
	if (ft_strchr_int(FLAGS, format[print->i]))
		get_field(format, print);
	if (format[print->i] >= 'A' && format[print->i] <= 'Z')
		print->upper = 1;
	while (format[print->i] != SPECIFY[x] && x < 26)
		x++;
	if (format[print->i] == SPECIFY[x])
	{
		print->conv = format[print->i];
		if (print->conv == 'c' && print->str != NULL)
			ft_strdel(&print->str);
		ret += g_table[x](print);
		if (print->str != NULL)
			print_conversion(print, ret);
	}
	else
		print->i--;
	return (1);
}

/*
** Parses through the format string until the next conversion or the null
** terminator, then writes what was found. If using printf and printing to
** standard output, it will also stop at the curly bracket (used for colours).
*/

int	convert_no(t_print *print, const char *format)
{
	int	i;

	i = 0;
	if (print->fd == STDOUT_FILENO)
	{
		while (format[i] != '\0' && format[i] != '%' && format[i] != '{')
			i++;
	}
	else
	{
		while (format[i] != '\0' && format[i] != '%')
			i++;
	}
	print->ret += write(print->fd, format, i);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:30:27 by abackman          #+#    #+#             */
/*   Updated: 2022/10/20 19:32:56 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	conv_asprint(t_print *p, const char *format)
{
	p->i = 0;
	p->ret = 0;
	while (format[p->i])
	{
		if (format[p->i] == '%')
		{
			p->i++;
			if (format[p->i] == '\0')
				break ;
			else if (ft_strchr_int(ALL, format[p->i]))
			{
				p->ret += as_convert_yes(p, format);
				p->i++;
			}
			else
				p->i += as_convert_no(p, &format[p->i]);
		}
		else
			p->i += as_convert_no(p, &format[p->i]);
	}
	return (p->ret);
}

static int	conv_print(t_print *p, const char *format)
{
	p->i = 0;
	p->ret = 0;
	while (format[p->i])
	{
		if (format[p->i] == '%')
		{
			p->i++;
			if (format[p->i] == '\0')
				break ;
			else if (ft_strchr_int(ALL, format[p->i]))
			{
				convert_yes(p, format);
				p->i++;
			}
			else
				p->i += convert_no(p, &format[p->i]);
		}
		else if (format[p->i] == '{' && p->fd == STDOUT_FILENO)
			p->i += check_colour(p, &format[p->i]);
		else
			p->i += convert_no(p, &format[p->i]);
	}
	return (p->ret);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	t_print	*print;
	int		ret;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	print->fd = 0;
	print->str = ft_strdup("");
	init_struct(print);
	va_start(print->ap, format);
	if (!ft_strlen_int(format))
	{
		free_struct(print);
		return (0);
	}
	ret = conv_asprint(print, format);
	va_end(print->ap);
	*str = ft_strdup(print->str);
	free_struct(print);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	print->str = ft_strdup("");
	init_struct(print);
	va_start(print->ap, format);
	if (!ft_strlen_int(format))
	{
		free_struct(print);
		return (0);
	}
	print->fd = fd;
	ret = conv_print(print, format);
	va_end(print->ap);
	free_struct(print);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (0);
	va_start(print->ap, format);
	if (!ft_strlen_int(format))
	{
		free_struct(print);
		return (0);
	}
	init_struct(print);
	print->fd = STDOUT_FILENO;
	print->str = ft_strdup("");
	ret = conv_print(print, format);
	va_end(print->ap);
	free_struct(print);
	return (ret);
}

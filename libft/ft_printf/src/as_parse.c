/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/07/07 12:21:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*p_strnew(const char *format, int i)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = format[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*p_strjoin(char *str, const char *format, int i)
{
	char	*new;
	int		j;
	int		k;
	int		l;

	j = ft_strlen_int(str) + i;
	new = (char *)malloc(j + 1 * sizeof(char));
	if (!new)
		return (NULL);
	k = 0;
	l = 0;
	while (str[k])
	{
		new[k] = str[k];
		k++;
	}
	while (k < j)
		new[k++] = format[l++];
	new[k] = '\0';
	ft_strdel(&str);
	return (new);
}

int	as_convert_yes(t_print *print, const char *format)
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
		ret += g_dispatch[x](print);
	}
	else
		print->i--;
	return (ret);
}

int	as_convert_no(t_print *print, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (print->str != NULL)
		print->str = p_strjoin(print->str, format, i);
	else
		print->str = p_strnew(format, i);
	print->ret += i;
	return (i);
}

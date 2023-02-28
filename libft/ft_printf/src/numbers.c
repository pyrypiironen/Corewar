/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:15:34 by abackman          #+#    #+#             */
/*   Updated: 2022/06/13 14:55:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Helper functions for float conversion.
*/

double	init_dot(long double num, long long whole, int prec)
{
	double		power;
	double		dot;

	power = 1;
	dot = 0;
	while (dot++ < prec)
		power *= 10;
	dot = (num - whole) * power;
	return (dot);
}

static char	*fl_swap_space(char *new)
{
	int		i;

	i = 0;
	while (new[i])
	{
		if (new[i] == ' ')
		{
			new[i] = new[0];
			new[0] = ' ';
			break ;
		}
		i++;
	}
	return (new);
}

static char	*fl_pad_right(t_print *p, char *new, char *tmp, int start)
{
	int		x;

	x = ft_strlen_int(tmp);
	while (start < x)
	{
		new[start] = tmp[start];
		start++;
	}
	while (x < p->width)
		new[x++] = ' ';
	new[x] = '\0';
	return (new);
}

static char	*fl_pad_left(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	int		save;
	char	pad;

	pad = '0';
	x = ft_strlen_int(tmp);
	new = ft_strcpy(new, (const char *)tmp);
	if (!p->fl_zero)
	{
		start = 0;
		pad = ' ';
	}
	save = start;
	while (start < (p->width - x + save))
		new[start++] = pad;
	x = save;
	while (tmp[x])
		new[start++] = tmp[x++];
	new[start] = '\0';
	if (p->space)
		new = fl_swap_space(new);
	return (new);
}

char	*fl_width(t_print *p, char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!p->width)
		return (str);
	while (!ft_isdigit((int)str[i]))
		i++;
	new = (char *)malloc(p->width + i + 1 * sizeof(char));
	if (!new)
		return (str);
	if (p->minus)
		new = fl_pad_right(p, new, str, 0);
	else
		new = fl_pad_left(p, new, str, i);
	ft_strdel(&str);
	return (new);
}

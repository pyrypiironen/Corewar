/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/06/13 14:55:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Pads the converted string to it's right.
*/

static char	*pad_right(t_print *p, char *new, char *tmp, int start)
{
	int		x;

	x = ft_strlen_int(tmp);
	if (p->precision != -1 && p->conv != 's' && p->zero)
		return (tmp);
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

/*
** Swaps the first space character found for the first character in a string.
*/

static char	*swap_space(char *new)
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

/*
** Pads the converted string to it's left.
*/

static char	*pad_left(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	int		save;
	char	pad;

	pad = '0';
	x = ft_strlen_int(tmp);
	new = ft_strcpy(new, (const char *)tmp);
	if ((!p->zero && p->conv != 'd' && p->conv != 'i' && p->conv != 'f') || \
	(!p->zero && !p->minus && !p->p_save))
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
	if ((p->conv == 'd' || p->conv == 'i' || p->conv == 'f') && p->space)
		new = swap_space(new);
	return (new);
}

/*
** Finds the starting point of the padding.
*/

static int	width_start(t_print *p, char *tmp)
{
	int	i;

	i = 0;
	if (p->conv == 'o' || p->conv == 'O' || p->conv == 'x' || p->conv == 'X')
	{
		i = p->hash;
		if (p->conv == 'x' || p->conv == 'X')
			i *= 2;
	}
	else if (p->conv == 'i' || p->conv == 'd' || p->conv == 'f')
	{
		if (tmp[0] == '+' || tmp[0] == '-')
			i = 1;
		if (tmp[0] == ' ')
			i = 1;
	}
	return (i);
}

/*
** Inserts the necessary padding if width is specified for a conversion.
*/

char	*insert_width(t_print *p, char *tmp, int free)
{
	char	*new;
	int		i;

	new = NULL;
	i = width_start(p, tmp);
	if (!p->width)
		return (tmp);
	if (p->width <= ft_strlen_int(tmp) && (p->conv != 'd' || p->conv != 'i' || \
	p->conv != 'f') && p->width)
		return (tmp);
	new = (char *)malloc(p->width + i + 1 * sizeof(char));
	if (!new)
		return (tmp);
	if (p->minus)
		new = pad_right(p, new, tmp, 0);
	else
		new = pad_left(p, new, tmp, i);
	if (free == 1)
		ft_strdel(&tmp);
	return (new);
}

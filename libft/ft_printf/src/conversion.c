/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/06/13 14:52:52 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for %%-specifier.
*/

int	pr_perc(t_print *print)
{
	char	*perc;

	perc = (char *)malloc(2 * sizeof(char));
	if (!perc)
		return (-1);
	perc[0] = '%';
	perc[1] = '\0';
	if (print->width)
		perc = insert_width(print, perc, 1);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, perc, 3);
	else
		print->str = perc;
	if (print->width)
		return (print->width);
	else
		return (1);
}

/*
** Conversion for %c-specifier.
*/

int	pr_char(t_print *print)
{
	char			*str;
	unsigned char	c;

	c = (unsigned char)va_arg(print->ap, int);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (print->width)
	{
		if (!ft_isprint(c))
			str = insert_space_only(print, str);
		else
			str = insert_width(print, str, 1);
	}
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, str, 1);
	else if (print->str == NULL)
		print->str = str;
	if (print->width)
		return (print->width);
	else
		return (1);
}

/*
** Conversion for %s-specifier.
*/

int	pr_str(t_print *print)
{
	char	*tmp;
	char	*new;
	int		i;

	i = 0;
	tmp = va_arg(print->ap, char *);
	if (tmp == NULL || !ft_strcmp(tmp, "") || (print->precision == 0 && \
	!print->check_neg))
		new = strnull(print, tmp);
	else
		new = ft_strdup(tmp);
	if (print->precision > 0 && !print->check_neg)
	{
		while (new[print->precision] != '\0')
			new[print->precision++] = '\0';
	}
	new = insert_width(print, new, 1);
	i = ft_strlen_int(new);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, new, 1);
	else
		print->str = ft_strdup(new);
	ft_strdel(&new);
	return (i);
}

/*
** Conversion for %p-specifier.
*/

int	pr_ptr(t_print *print)
{
	char			*tmp;
	int				i;
	unsigned long	p;

	i = 0;
	p = 0;
	p = va_arg(print->ap, unsigned long);
	tmp = ft_utoa_base(p, 16, print);
	i = ft_strlen_int(tmp);
	tmp = strjoin_pro("0x", tmp, 2);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen_int(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
	else if (print->str == NULL)
		print->str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (i);
}

/*
** Conversion for %x and %X-specifier, unsigned number to hexadecimal.
*/

int	pr_hex(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 16, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	if (print->hash && p)
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen_int(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
	else if (print->str == NULL)
		print->str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (i);
}

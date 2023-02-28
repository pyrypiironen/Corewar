/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:10:23 by abackman          #+#    #+#             */
/*   Updated: 2022/06/13 14:53:31 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for signed integers.
*/

int	pr_num(t_print *print)
{
	char				*tmp;
	int					i;
	long long			p;

	i = 0;
	p = signed_length_mod(print);
	tmp = ft_itoa_base(p, 10, print);
	if (print->precision != -1 && (!print->check_neg || !print->p_save))
		tmp = zeropad(tmp, print->precision, p);
	if (print->space && p >= 0 && !print->plus)
		tmp = strjoin_pro(" ", tmp, 2);
	if (print->plus && p >= 0)
		tmp = strjoin_pro("+", tmp, 2);
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
** Conversion of an unsigned int to binary string.
*/

int	pr_bin(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 2, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen_int(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
	else if (print->str == NULL)
		print->str = p_strnew(tmp, i);
	ft_strdel(&tmp);
	return (i);
}

/*
** Octal conversion.
*/

int	pr_oct(t_print *print)
{
	char				*tmp;
	int					i;
	int					new_prec;
	unsigned long long	p;

	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 8, print);
	i = ft_strlen_int(tmp);
	new_prec = print->precision;
	if (print->hash && p && (new_prec == 0 || new_prec == -1 || new_prec == i))
		new_prec = i + 1;
	if (new_prec != -1)
		tmp = zeropad(tmp, new_prec, p);
	if ((!p && !print->precision && print->hash))
		tmp = strjoin_pro("0", tmp, 2);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen_int(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
	else if (print->str == NULL)
		print->str = p_strnew(tmp, i);
	ft_strdel(&tmp);
	return (i);
}

/*
** Conversion for unsigned integers.
*/

int	pr_u(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 10, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen_int(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
	else if (print->str == NULL)
		print->str = p_strnew(tmp, i);
	ft_strdel(&tmp);
	return (i);
}

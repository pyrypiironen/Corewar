/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:30:30 by abackman          #+#    #+#             */
/*   Updated: 2022/08/09 12:56:26 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*decimal_str(t_print *p, int prec, unsigned long long tmp, \
char *buf)
{
	int	i;

	i = 0;
	while (tmp > 0)
	{
		buf[i++] = tmp % 10 + '0';
		tmp /= 10;
	}
	while (i < prec)
		buf[i++] = '0';
	if (p->precision != 0 || p->hash)
		buf[i++] = '.';
	if (prec > 0)
	{
		buf[i] = '\0';
		str_reverse(buf);
	}
	else
		buf[i - 2] = '\0';
	return (buf);
}

static char	*after_decimal(t_print *p, char *nbr, long double num, \
long long whole)
{
	char				*buf;
	unsigned long long	tmp;
	double				dot;
	int					prec;

	dot = 0.0;
	if (p->precision == -1)
		prec = 6;
	else if (p->precision < 19)
		prec = p->precision;
	else
		prec = 19;
	dot = init_dot(num, whole, prec);
	tmp = (unsigned long long)dot;
	buf = (char *)malloc(prec + 2 * sizeof(char));
	if (!buf)
		return (NULL);
	buf = decimal_str(p, prec, tmp, buf);
	buf = strjoin_pro(nbr, buf, 3);
	return (buf);
}

static char	*float_signs(t_print *p, char *old, long double num)
{
	int		len;
	char	tmp[5];

	len = 0;
	if (1 / num < 0)
		tmp[len++] = '-';
	else if (p->space && !p->plus)
		tmp[len++] = ' ';
	else if (p->plus)
		tmp[len++] = '+';
	tmp[len] = '\0';
	if (tmp[0] == '\0')
		return (old);
	else
		return (strjoin_pro(tmp, old, 2));
}

int	pr_float(t_print *p)
{
	char				*nbr_str;
	long double			num;
	unsigned long long	whole;
	int					ret;
	long double			save;

	ret = 0;
	num = float_length_mod(p);
	save = num;
	if (num < 0.000000 || 1 / num < 0)
		num *= -1;
	if (p->precision != 0 || num > 0.999999)
		num = ftoa_rounding(p->precision, num);
	whole = (unsigned long)num;
	nbr_str = ft_utoa_base(whole, 10, p);
	nbr_str = after_decimal(p, nbr_str, num, whole);
	nbr_str = float_signs(p, nbr_str, save);
	nbr_str = fl_width(p, nbr_str);
	ret = ft_strlen_int((const char *)nbr_str);
	if (p->str != NULL)
		p->str = strjoin_pro(p->str, nbr_str, 1);
	else if (p->str == NULL)
		p->str = p_strnew((const char *)nbr_str, ret);
	ft_strdel(&nbr_str);
	return (ret);
}

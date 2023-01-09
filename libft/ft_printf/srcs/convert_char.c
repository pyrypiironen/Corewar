/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:27:21 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/30 16:27:22 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_char(va_list ap, t_struct *d)
{
	char		*print;

	print_it(d);
	d->arg = (char)va_arg(ap, int);
	d->print_len = 1;
	if (d->width > 1)
		d->print_len = d->width;
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print_char(d, print);
	adjust_left_char(d, print);
	if (d->width == 0)
		d->width = 1;
	write(1, print, d->width);
	d->res += d->width;
	free(print);
}

void	fill_print_char(t_struct *d, char *print)
{
	int	i;
	int	len;

	i = 0;
	len = d->print_len;
	while (len - 1 > 0)
	{
		if (d->zero == 1)
			print[i] = '0';
		else
			print[i] = ' ';
		len--;
		i++;
	}
	print[i] = d->arg;
}

void	adjust_left_char(t_struct *d, char *print)
{
	int	i;
	int	k;

	i = 0;
	k = d->width;
	if (d->minus == 0)
		return ;
	while (k > 0)
	{
		while (print[i] == ' ')
			i++;
		if (i == 0)
			return ;
		while (i < k)
		{
			print[i - 1] = print[i];
			print[i] = ' ';
			i++;
		}
		i = 0;
		k--;
	}
}

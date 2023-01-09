/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:48:13 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/20 16:48:14 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_int(va_list ap, t_struct *d)
{
	char		*input;
	char		*print;

	read_arg(d, ap);
	input = ft_itoa(d->arg);
	d->input_len = ft_strlen(input);
	d->print_len = print_len(d);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print(d, print);
	plant_arg(d, print, input);
	zero_precision_check(d, print);
	adjust_left(d, print);
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(input);
	free(print);
}

int	print_len(t_struct *d)
{
	int	len;
	int	flag;

	len = d->input_len;
	flag = 0;
	if ((d->plus == 1 || d->space == 1) && d->arg >= 0)
	{
		flag = 1;
		len++;
	}
	if (d->width > len)
		len = d->width;
	if (d->padding + flag > len)
		len = d->padding + flag;
	if (d->padding >= d->width && d->padding >= d->input_len && d->arg < 0)
		len++;
	return (len);
}

void	plant_arg(t_struct *d, char *print, char *input)
{
	int	i;

	while (d->input_len >= 0 && input[d->input_len] != '-')
		print[d->print_len--] = input[d->input_len--];
	i = d->print_len;
	if (d->plus == 1 && d->arg >= 0)
	{
		while (print[i] == '0' && i > 0)
			i--;
		print[i] = '+';
	}
	else if (d->space == 1)
	{
		while (print[i] == '0' && i > 0)
			i--;
		print[i] = ' ';
	}
	i = d->print_len;
	while (print[i] != ' ' && i > 0)
		i--;
	if (d->arg < 0)
		print[i] = '-';
}

void	read_arg(t_struct *d, va_list ap)
{
	if (d->mod_l == 1)
		d->arg = (long)va_arg(ap, long);
	else if (d->mod_ll == 1)
		d->arg = (long long)va_arg(ap, long long);
	else if (d->mod_h == 1)
		d->arg = (short)va_arg(ap, int);
	else if (d->mod_hh == 1)
		d->arg = (signed char)va_arg(ap, int);
	else
		d->arg = (int)va_arg(ap, int);
}

void	zero_precision_check(t_struct *d, char *print)
{
	int	i;

	i = 0;
	if (d->padding != 0 || d->arg != 0)
		return ;
	while (i < d->width)
	{
		print[i] = ' ';
		i++;
	}
	print[i] = '\0';
	if (d->width == 0)
		i = 1;
	if (d->conv_o == 1 && d->hash == 1)
	{
		print[i - 1] = '0';
		print[i] = '\0';
	}
}

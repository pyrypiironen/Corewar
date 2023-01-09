/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:59:21 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/20 14:59:22 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_binary(const char *format, va_list ap, t_struct *d)
{
	char		*input;
	char		*print;

	input = prepare_input(format, ap, d);
	d->input_len = ft_strlen(input);
	print_len_binary(d);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print_binary(d, print, input);
	adjust_left(d, print);
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(input);
	free(print);
}

char	*prepare_input(const char *format, va_list ap, t_struct *d)
{
	char	*input;

	input = NULL;
	d->pos++;
	if (format[d->pos] == 'd' || format[d->pos] == 'i')
	{
		read_arg(d, ap);
		input = ft_itoa_base(d->arg, 2);
	}
	else if (format[d->pos] == 'u')
	{
		read_arg_unsigned(d, ap);
		input = ft_itoa_base(d->arg_o, 2);
	}
	return (input);
}

void	print_len_binary(t_struct *d)
{
	d->print_len = d->width;
	if (d->mod_h == 1)
		d->padding = 16;
	else if (d->mod_hh == 1)
		d->padding = 8;
	else if (d->mod_ll == 1)
		d->padding = 64;
	else
		d->padding = 32;
	if (d->padding > d->width)
		d->print_len = d->padding;
}

void	fill_print_binary(t_struct *d, char *print, char *input)
{
	int	i;
	int	pad;

	pad = d->padding;
	i = d->print_len - 1;
	while (d->padding > 0)
	{
		print[i] = '0';
		d->padding--;
		i--;
	}
	while (i >= 0)
	{
		print[i] = ' ';
		i--;
	}
	while (d->input_len >= 0 && pad >= 0)
	{
		print[d->print_len] = input[d->input_len];
		d->input_len--;
		d->print_len--;
		pad--;
	}
	if (d->arg < 0)
				print[d->print_len + 1] = '1';
}

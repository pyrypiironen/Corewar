/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:48:28 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/28 14:48:29 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_octal(va_list ap, t_struct *d)
{
	char		*input;
	char		*print;

	d->conv_o = 1;
	read_arg_unsigned(d, ap);
	input = ft_itoa_base(d->arg_o, 8);
	d->input_len = ft_strlen(input);
	d->print_len = print_len_unsigned(d, d->input_len);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print(d, print);
	plant_arg_unsigned(d, print, input);
	zero_precision_check_unsigned(print, d);
	adjust_left(d, print);
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(input);
	free(print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:19:51 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/06 16:19:53 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_pointer(va_list ap, t_struct *d)
{
	char		*input;
	char		*print;

	d->conv_p = 1;
	d->arg_o = va_arg(ap, unsigned long long);
	input = ft_itoa_base(d->arg_o, 16);
	d->input_len = ft_strlen(input);
	d->print_len = print_len_unsigned(d, d->input_len);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(0);
	print[d->print_len] = '\0';
	fill_print(d, print);
	plant_arg_unsigned(d, print, input);
	adjust_left(d, print);
	to_lowercase(print);
	zero_precision_check_unsigned(print, d);
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(input);
	free(print);
}

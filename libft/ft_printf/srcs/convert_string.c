/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:28:51 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/30 18:28:52 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_string(va_list ap, t_struct *d)
{
	char	*input;
	char	*print;

	if (d->s_pad == -1)
		d->padding = -1;
	input = ft_strdup((char *)va_arg(ap, char *));
	if (input == NULL)
		input = ft_strdup("(null)");
	d->input_len = ft_strlen(input);
	print_len_str(d);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print_str(d, print, input);
	adjust_left(d, print);
	d->res += ft_strlen(print);
	if (ft_strlen(print) + d->pos >= 420)
		print_it(d);
	if (ft_strlen(print) + d->pos >= 420)
		ft_putstr(print);
	else
		add_to_print(print, d);
	free(input);
	free(print);
}

void	fill_print_str(t_struct *d, char *print, char *input)
{
	if (d->padding >= 0 && d->padding < d->input_len)
		input[d->padding] = '\0';
	d->input_len = ft_strlen(input);
	while (d->print_len >= 0 && d->input_len >= 0)
	{
		print[d->print_len] = input[d->input_len];
		d->print_len--;
		d->input_len--;
	}
	while (d->print_len >= 0)
	{
		print[d->print_len] = ' ';
		d->print_len--;
	}
}

void	print_len_str(t_struct *d)
{
	d->print_len = d->input_len;
	if (d->padding >= 0 && d->padding < d->print_len)
		d->print_len = d->padding;
	if (d->width > d->print_len)
		d->print_len = d->width;
}

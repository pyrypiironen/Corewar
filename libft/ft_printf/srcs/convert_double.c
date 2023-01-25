/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:22:13 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/13 16:29:02 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_double(va_list ap, t_struct *d)
{
	char		*input;
	char		*print;

	if (d->padding == -1)
		d->padding = 6;
	read_arg_double(d, ap);
	rounders(d);
	input = dtoa(d->padding, d);
	d->input_len = ft_strlen(input);
	d->print_len = print_len_double(d);
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	fill_print_double(d, print);
	plant_arg_double(d, print, input);
	adjust_left(d, print);
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(input);
	free(print);
}

void	rounders(t_struct *d)
{
	int			i;
	int			j;
	long double	banker;
	char		*alpha;

	i = 0;
	j = 0;
	banker = d->arg_f;
	alpha = fractional_part(d->arg_f, 19, d);
	while (j < d->padding)
	{
		banker *= 10;
		j++;
	}
	j = 0;
	while (j <= d->padding && j < 19)
	{
		i = -1;
		while (++i < 18)
			alpha[i] = alpha[i + 1];
		alpha[18] = '0';
		j++;
	}
	bankers_rounding(d, banker, alpha);
	free(alpha);
}

void	bankers_rounding(t_struct *d, long double banker, char *alpha)
{
	int			i;

	d->rounding = 0.5;
	i = 0;
	if ((ft_strncmp(alpha, "4999999", 7) == 0 || \
		ft_strcmp(alpha, "50000000000000000000") == 0) && \
		((long long)banker % 2 == 0) && d->padding < 3)
		d->rounding = -0.25;
	else if (ft_strncmp(alpha, "4999999", 7) == 0 \
			&& ((long long)banker % 2 == 0) && d->mod_big_l == 1)
		d->rounding = -0.25;
	if (d->arg_f < 0)
		d->rounding *= -1;
	while (i < d->padding)
	{
		d->rounding /= 10.0;
		i++;
	}
	d->arg_f += d->rounding;
}

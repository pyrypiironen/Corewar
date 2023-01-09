/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:06:04 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/04 13:06:05 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_modulo(t_struct *d)
{
	char	*print;
	int		i;

	i = 0;
	d->print_len = 1;
	if (d->width > 1)
		d->print_len = d->width;
	print = (char *)malloc(sizeof(*print) * d->print_len + 1);
	if (print == NULL)
		exit(-1);
	print[d->print_len] = '\0';
	while (i < d->width)
	{
		if (d->zero == 1 && d->minus == 0)
			print[i++] = '0';
		else
			print[i++] = ' ';
	}
	if (d->minus == 0)
		print[d->print_len - 1] = '%';
	else
		print[0] = '%';
	add_to_print(print, d);
	d->res += ft_strlen(print);
	free(print);
}

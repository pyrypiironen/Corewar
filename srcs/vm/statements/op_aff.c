/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:01:55 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 14:01:57 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

// This statement takes a value from a registry that was passed as a single
//argument. Converts it to type char. And displays as an ASCII character.
void	op_aff(t_carriage *carriage, t_vm_data *d)
{
	int		value;
	char	printable;

	value = d->arena[(carriage->cursor + 2) % MEM_SIZE];
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x40 && \
	is_valid_reg((carriage->cursor + 2) % MEM_SIZE, d))
	{
		printable = (char)carriage->registrys[value - 1];
		if (d->b_flag == 0 && printable > 32 && printable < 127)
			ft_printf("Aff: %c\n", printable);
		else if (d->a_flag != -2)
			ft_printf("Aff: %c\n", printable);
		carriage->cursor = (carriage->cursor + 3) % MEM_SIZE;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 1)) % MEM_SIZE;
}

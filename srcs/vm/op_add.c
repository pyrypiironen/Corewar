/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:46 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/13 14:06:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_valid_add_sub(t_carriage *carriage, t_vm_data *d);

// This statements add sum of argument 1 and argument 2 to argument 3.
// All arguments are registrys. Also update the carry.
void	op_add(t_carriage *carriage, t_vm_data *d)
{
	int	first;
	int	second;
	int third;

	first = d->arena[(carriage->cursor + 2) % MEM_SIZE] - 1;
	second = d->arena[(carriage->cursor + 3) % MEM_SIZE] - 1;
	third = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x54 && \
	is_valid_add_sub(carriage, d))
	{
		carriage->registrys[third] = carriage->registrys[first] +\
		carriage->registrys[second];
		carriage->carry = update_carry(carriage->registrys[third]);
		if (d->a_flag != -2)
			ft_printf("P      | add r%d r%d r%d\n", first + 1, second + 1, \
			third + 1);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 3)) % MEM_SIZE;
}

// This statement add argument 1 reduced of argument 2 to argument 3.
// All arguments are registrys. Also update the carry.
void	op_sub(t_carriage *carriage, t_vm_data *d)
{
	int	first;
	int	second;
	int third;

	first = d->arena[(carriage->cursor + 2) % MEM_SIZE] - 1;
	second = d->arena[(carriage->cursor + 3) % MEM_SIZE] - 1;
	third = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x54 &&\
	is_valid_add_sub(carriage, d))
	{
		carriage->registrys[third] = carriage->registrys[first] -\
		carriage->registrys[second];
		carriage->carry = update_carry(carriage->registrys[third]);
		if (d->a_flag != -2)
			ft_printf("P     | sub r%d r%d r%d\n", first + 1, second + 1, \
			third + 1);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 3)) % MEM_SIZE;
}

// Check that all arguments are valid regitrys.
static int	is_valid_add_sub(t_carriage *carriage, t_vm_data *d)
{
	if (!is_valid_reg((carriage->cursor + 2) % MEM_SIZE, d))
		return (0);
	if (!is_valid_reg((carriage->cursor + 3) % MEM_SIZE, d))
		return (0);
	if (!is_valid_reg((carriage->cursor + 4) % MEM_SIZE, d))
		return (0);
	return (1);
}

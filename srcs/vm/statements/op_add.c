/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:46 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 12:47:47 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static int	is_valid_add_sub(t_carriage *carriage, t_vm_data *d);

void	op_add(t_carriage *carriage, t_vm_data *d)
{
	int	first;
	int	second;
	int third;

	first = d->arena[(carriage->cursor + 2) % MEM_SIZE] - 1;
	second = d->arena[(carriage->cursor + 3) % MEM_SIZE] - 1;
	third = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
	carriage->jump_size = 5;
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x54 && \
	is_valid_add_sub(carriage, d))
	{
		carriage->registrys[third] = carriage->registrys[first] +\
		carriage->registrys[second];
		carriage->carry = update_carry(carriage->registrys[third]);
		if (d->a_flag != -2)
			ft_printf("P%5d | add r%d r%d r%d\n", carriage->id, \
			first + 1, second + 1, third + 1);
	}
	carriage->cursor = (carriage->cursor + carriage->jump_size) % MEM_SIZE;
	// Or should we read argument value code.
}

void	op_sub(t_carriage *carriage, t_vm_data *d)
{
	int	first;
	int	second;
	int third;

	first = d->arena[(carriage->cursor + 2) % MEM_SIZE] - 1;
	second = d->arena[(carriage->cursor + 3) % MEM_SIZE] - 1;
	third = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
	carriage->jump_size = 5;
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x54 &&\
	is_valid_add_sub(carriage, d))
	{
		carriage->registrys[third] = carriage->registrys[first] -\
		carriage->registrys[second];
		carriage->carry = update_carry(carriage->registrys[third]);
		if (d->a_flag != -2)
			ft_printf("P%5d | sub r%d r%d r%d\n", carriage->id, \
			first + 1, second + 1, third + 1);
	}
	carriage->cursor = (carriage->cursor + carriage->jump_size) % MEM_SIZE;
	// Or should we read argument value code.
}

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

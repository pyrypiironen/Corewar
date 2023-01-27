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
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x54 &&\
	is_valid_add_sub(carriage, d))
	{
		carriage->registrys[third] = carriage->registrys[first] +\
		carriage->registrys[second];
		if (carriage->registrys[third] == 0)
			carriage->carry = 1;
		else
			carriage->carry = 0;
	}
	carriage->cursor = (carriage->cursor + carriage->jump_size) % MEM_SIZE;
	carriage->jump_size = 0;			// is needed?
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
		if (carriage->registrys[third] == 0)
			carriage->carry = 1;
		else
			carriage->carry = 0;
	}
	carriage->cursor = (carriage->cursor + carriage->jump_size) % MEM_SIZE;
	carriage->jump_size = 0;			// is needed?
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

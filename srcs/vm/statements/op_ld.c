/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:46:10 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/30 15:46:11 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static void	ld_actions(t_vm_data *d, t_carriage *carriage, int value, \
unsigned char reg);

// Load statement. The task of this statement is to load the value (T_DIR or 
// T_IND) into the registry. Can't load further than 512 memory location away.
// Also update value of carry if needed.
void	op_ld(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	reg;
	int				value;

	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x90 && \
	is_valid_reg((carriage->cursor + 6) % MEM_SIZE, d))
	{
		reg = d->arena[(carriage->cursor + 6) % MEM_SIZE] - 1;
		value = get_4_byte_value(d, carriage->cursor + 2);
		carriage->registrys[reg] = value;
		ld_actions(d, carriage, value, reg);
		carriage->cursor = (carriage->cursor + 7) % MEM_SIZE;
	}
	else if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0xd0 && \
	is_valid_reg((carriage->cursor + 4) % MEM_SIZE, d))
	{
		reg = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
		value = get_4_byte_value(d, (carriage->cursor + \
		get_2_byte_value(d, (carriage->cursor + 2), 1)) % MEM_SIZE);
		carriage->registrys[reg] = value;
		ld_actions(d, carriage, value, reg);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 2)) % MEM_SIZE;
}

// Long load statement. Same than load statement, but can load further than
// 512 memory location away.
void	op_lld(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	reg;
	int				value;

	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x90 && \
	is_valid_reg((carriage->cursor + 6) % MEM_SIZE, d))
	{
		reg = d->arena[(carriage->cursor + 6) % MEM_SIZE] - 1;
		value = get_4_byte_value(d, carriage->cursor + 2);
		carriage->registrys[reg] = value;
		carriage->carry = update_carry(value);
		carriage->cursor = (carriage->cursor + 7) % MEM_SIZE;
	}
	else if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0xd0 && \
	is_valid_reg((carriage->cursor + 4) % MEM_SIZE, d))
	{
		reg = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
		value = get_4_byte_value(d, carriage->cursor + \
		get_2_byte_value(d, (carriage->cursor + 2), 0));
		carriage->registrys[reg] = value;
		carriage->carry = update_carry(value);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 2)) % MEM_SIZE;
}

// Update carry to op_ld and print information of actions if -a flag is on.
static void	ld_actions(t_vm_data *d, t_carriage *carriage, int value, \
unsigned char reg)
{
	carriage->carry = update_carry(value);
	if (d->a_flag != -2)
		ft_printf("P      | ld %d r%d\n", value, reg + 1);
}
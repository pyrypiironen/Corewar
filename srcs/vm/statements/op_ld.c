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
		carriage->carry = update_carry(value);
		carriage->cursor = (carriage->cursor + 7) % MEM_SIZE;
	}
	else if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0xd0 && \
	is_valid_reg((carriage->cursor + 4) % MEM_SIZE, d))
	{
		reg = d->arena[(carriage->cursor + 4) % MEM_SIZE] - 1;
		value = get_4_byte_value(d, carriage->cursor + \
		get_2_byte_value(d, (carriage->cursor + 2), 1));
		carriage->registrys[reg] = value;
		carriage->carry = update_carry(value);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		;// Jump over 5 or 7 bytes?????????
}

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
		;// Jump over 5 or 7 bytes?????????
}
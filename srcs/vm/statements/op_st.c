/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:49:11 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/30 17:49:14 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

void	op_st(t_carriage *carriage, t_vm_data *d)
{
	int	first;
	int	second;
	int	position;

	first = (carriage->cursor + 2) % MEM_SIZE;
	second = (carriage->cursor + 3) % MEM_SIZE;
	if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x50 && \
	is_valid_reg(first, d) && is_valid_reg(second, d))
	{
		carriage->registrys[d->arena[second] - 1] = \
		carriage->registrys[d->arena[first] - 1];
		carriage->cursor = (carriage->cursor + 4) % MEM_SIZE;
	}
	else if (d->arena[(carriage->cursor + 1) % MEM_SIZE] == 0x70 && \
	is_valid_reg(first, d))
	{
		position = (carriage->cursor + get_2_byte_value(d, \
		carriage->cursor + 3, 1)) % MEM_SIZE;
		int_to_arena(d, position, carriage->registrys[d->arena[first] - 1]);
		carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
	}
	else
		; //Just move cursor 4 or 5 bytes ??????
}

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

static long long	get_second_arg(t_carriage *carriage, t_vm_data *d);
static long long	get_third_arg(t_carriage *carriage, t_vm_data *d);

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
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 2)) % MEM_SIZE;
}



void	op_sti(t_carriage *carriage, t_vm_data *d)
{
	int			arg_1; // Actually index for reg, name this better
	long long	arg_2;
	long long	arg_3;
	int			pos;

	arg_1 = d->arena[(carriage->cursor + 2) % MEM_SIZE] - 1;
	arg_2 = get_second_arg(carriage, d);
	arg_3 = get_third_arg(carriage, d);
	if (is_valid_reg((carriage->cursor + 2) % MEM_SIZE, d) && \
		arg_2 != 2147483648 && arg_3 != 2147483648)
	{
		pos = (carriage->cursor + (arg_2 + arg_3) % IDX_MOD) % MEM_SIZE;
		int_to_arena(d, pos, carriage->registrys[arg_1]);
		carriage->cursor = carriage->cursor_copy;
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 2, 3)) % MEM_SIZE;
}

static long long	get_second_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = (carriage->cursor + 3) % MEM_SIZE;
	if ((res == 0x54 || res == 0x58) && is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (pos + 1) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}
		
	else if (res == 0x64 || res == 0x68)
	{
		carriage->cursor_copy = (pos + 2) % MEM_SIZE;
		return (get_2_byte_value(d, pos, 0));
	}
		
	else if (res == 0x74 || res == 0x78)
	{
		carriage->cursor_copy = (pos + 2) % MEM_SIZE;
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}

static long long	get_third_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = carriage->cursor_copy;
	if (((res == 0x54 || res == 0x64 || res == 0x74)) && is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (carriage->cursor_copy + 1) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}
		
	else if (res == 0x58 || res == 0x68 || res == 0x78)
	{
		carriage->cursor_copy = (carriage->cursor_copy + 2) % MEM_SIZE;
		return (get_2_byte_value(d, pos, 0));
	}
	return (2147483648);
}

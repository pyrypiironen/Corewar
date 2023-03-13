/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_load_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:46:44 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/13 13:46:45 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static long long	get_first_arg(t_carriage *carriage, t_vm_data *d);
static long long	get_second_arg(t_carriage *carriage, t_vm_data *d);

// Load index.
// This statement writes the 4 byte value to the registry, which was passed to 
// it as the third parameter. Reads the value at the address, which is formed 
// according to the following principle:
// current position + (<first arg value> + <second arg value>) % IDX_MOD.
void	op_ldi(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			reg;
	int			pos;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	reg = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		pos = move_cursor(carriage, (arg_1 + arg_2) % IDX_MOD);
		carriage->registrys[reg] = get_4_byte_value(d, pos);
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		if (d->a_flag != -2)
			ft_printf("P      | ldi %d %d r%d\n       | -> load from %d + %d = \
%d (with pc and mod %d)\n", \
	 		arg_1, arg_2, reg + 1, arg_1, arg_2, arg_1 + arg_2, pos);
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 2, 3)) % MEM_SIZE;
}

// Long load index.
// Statement lldi. Same than statement ldi, but can load further than
// 512 memory location away.
void	op_lldi(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			reg;
	int			pos;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	reg = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		pos = move_cursor(carriage, arg_1 + arg_2);
		carriage->registrys[reg] = get_4_byte_value(d, pos);
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		if (d->a_flag != -2)
		 ft_printf("P      | lldi %d %d r%d\n       | -> load from %d + %d = %d\
 (with pc %d)\n", arg_1, arg_2, reg + 1, arg_1, arg_2, arg_1 + arg_2, pos);
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 2, 3)) % MEM_SIZE;
}

// Read argument type code and based on that, get first value from T_REG,
// T_DIR or T_IND.
static long long	get_first_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = (carriage->cursor + 2) % MEM_SIZE;
	carriage->cursor_copy = carriage->cursor;
	if (((res == 0x54 && is_valid_reg((pos + 1) % MEM_SIZE, d)) || res == 0x64)\
		&& is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (carriage->cursor + 3) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}
	else if ((res == 0x94 && is_valid_reg((pos + 2) % MEM_SIZE, d)) || \
	res == 0xa4)
	{
		carriage->cursor_copy = (carriage->cursor + 4) % MEM_SIZE;
		return (get_2_byte_value(d, pos, 0));
	}
	else if ((res == 0xd4 && is_valid_reg((pos + 2) % MEM_SIZE, d)) \
		|| res == 0xe4)
	{
		carriage->cursor_copy = (carriage->cursor + 4) % MEM_SIZE;
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}

// Read argument type code and based on that, get second value from T_REG
// or T_DIR.
static long long	get_second_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = carriage->cursor_copy;
	if (((res == 0x54 || res == 0x94 || res == 0xd4)) && is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (carriage->cursor_copy + 1) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}	
	else if (res == 0x64 || res == 0xa4 || res == 0xe4)
	{
		carriage->cursor_copy = (carriage->cursor_copy + 2) % MEM_SIZE;
		return (get_2_byte_value(d, pos, 0));
	}
	return (2147483648);
}

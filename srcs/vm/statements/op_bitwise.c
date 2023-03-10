/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:35:42 by mjokela           #+#    #+#             */
/*   Updated: 2023/02/01 14:35:48 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static long long	get_first_arg(t_carriage *carriage, t_vm_data *d);
static long long	get_second_arg(t_carriage *carriage, t_vm_data *d);

// This statement performs a "bitwise AND" statement for the values ​of the first
// two arguments and writes the result to the registry passed as the third
// argument. Also update the carry.
void	op_and(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	d->carriage->cursor_copy = 0;
	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 & (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
		if (d->a_flag != -2)
			ft_printf("P      | and %d %d r%d\n", \
			arg_1, arg_2, arg_3 + 1);
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 3)) % MEM_SIZE;
}

// Same than op_and, but "bitwise AND" is replaced by "bitwise OR".
void	op_or(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	d->carriage->cursor_copy = 0;
	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 | (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
		if (d->a_flag != -2)
			ft_printf("P      | or %d %d r%d\n", \
			arg_1, arg_2, arg_3 + 1);
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 3)) % MEM_SIZE;
}

// Same than op_or, but "bitwise OR" is replaced by "bitwise exclusive OR".
void	op_xor(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	d->carriage->cursor_copy = 0;
	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 ^ (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
		if (d->a_flag != -2)
			ft_printf("P      | xor %d %d r%d\n", \
			arg_1, arg_2, arg_3 + 1);
	}
	else
		carriage->cursor = (carriage->cursor \
		+ count_jump_size(carriage, d, 4, 3)) % MEM_SIZE;
}

// Read argument type code and based on that, get first value from T_REG,
// T_DIR or T_IND.
static long long	get_first_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = (carriage->cursor + 2) % MEM_SIZE;
	if (((res == 0x54 && is_valid_reg((pos + 1) % MEM_SIZE, d)) || res == 0x64 \
		|| res == 0x74) && is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (carriage->cursor + 3) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}
		
	else if ((res == 0x94 && is_valid_reg((pos + 4) % MEM_SIZE, d)) \
		|| res == 0xa4 || res == 0xb4)
	{
		carriage->cursor_copy = (carriage->cursor + 6) % MEM_SIZE;
		return (get_4_byte_value(d, pos));
	}
		
	else if ((res == 0xd4 && is_valid_reg((pos + 2) % MEM_SIZE, d)) \
		|| res == 0xe4 || res == 0xf4)
	{
		carriage->cursor_copy = (carriage->cursor + 4) % MEM_SIZE;
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}

// Read argument type code and based on that, get second value from T_REG,
// T_DIR or T_IND.
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
		carriage->cursor_copy = (carriage->cursor_copy + 4) % MEM_SIZE;
		return (get_4_byte_value(d, pos));
	}
		
	else if (res == 0x74 || res == 0xb4 || res == 0xf4)
	{
		carriage->cursor_copy = (carriage->cursor_copy + 2) % MEM_SIZE;
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}
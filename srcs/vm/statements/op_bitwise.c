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

static long long get_first_arg(t_carriage *carriage, t_vm_data *d);
static long long get_second_arg(t_carriage *carriage, t_vm_data *d);

void	op_and(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 & (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
	}
	else
		ft_printf("{purple}error in and function\n"); // skip somewhere
}

void	op_or(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 | (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
	}
	else
		ft_printf("{purple}error in or function\n"); // skip somewhere
}

void	op_xor(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		carriage->registrys[arg_3] = (int)arg_1 ^ (int)arg_2;
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
		carriage->carry = update_carry(carriage->registrys[arg_3]);
	}
	else
		ft_printf("{purple}error in or function\n"); // skip somewhere
}
/*
01 01 01 00 REG REG REG == 0x54 == 1 + 1 + 1 - tested
01 10 01 00 REG DIR REG == 0x64 == 1 + 4 + 1 - tested
01 11 01 00 REG IND REG == 0x74 == 1 + 2 + 1 - tested
10 01 01 00 DIR REG REG == 0x94 == 4 + 1 + 1 - tested
10 10 01 00 DIR DIR REG == 0xa4 == 4 + 4 + 1 - tested
10 11 01 00 DIR IND REG == 0xb4 == 4 + 2 + 1 - tested
11 01 01 00 IND REG REG == 0xd4 == 2 + 1 + 1 - tested
11 10 01 00 IND DIR REG == 0xe4 == 2 + 4 + 1 - tested
11 11 01 00 IND IND REG == 0xf4 == 2 + 2 + 1 - tested
*/


static long long get_first_arg(t_carriage *carriage, t_vm_data *d)
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
		
	else if (((res == 0x94 && is_valid_reg((pos + 4) % MEM_SIZE, d)) \
		|| res == 0xa4 || res == 0xb4))
	{
		carriage->cursor_copy = (carriage->cursor + 6) % MEM_SIZE;
		return (get_4_byte_value(d, pos));
	}
		
	else if (((res == 0xd4 && is_valid_reg((pos + 2) % MEM_SIZE, d)) \
		|| res == 0xe4 || res == 0xf4))
	{
		carriage->cursor_copy = (carriage->cursor + 4) % MEM_SIZE;
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}

static long long get_second_arg(t_carriage *carriage, t_vm_data *d)
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
		ft_printf("value: %d \n", (carriage->cursor + get_2_byte_value(d, pos, 1)) % 4096);
		ft_printf("cursor: %d \n", carriage->cursor);
		return (get_4_byte_value(d, carriage->cursor + \
			get_2_byte_value(d, pos, 1)));
	}
	return (2147483648);
}
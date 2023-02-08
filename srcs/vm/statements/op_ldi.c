

# include "../../../includes/vm.h"

static long long	get_first_arg(t_carriage *carriage, t_vm_data *d);
static long long	get_second_arg(t_carriage *carriage, t_vm_data *d);

void	op_ldi(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;  // Actually index for reg, name this better
	int			pos;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		pos = (carriage->cursor + (arg_1 + arg_2) % IDX_MOD) % MEM_SIZE;
		carriage->registrys[arg_3] = get_4_byte_value(d, pos);
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
	}
	else
		ft_printf("{purple}error in and function\n"); // skip somewhere
}

void	op_lldi(t_carriage *carriage, t_vm_data *d)
{
	long long	arg_1;
	long long	arg_2;
	int			arg_3;  // Actually index for reg, name this better
	int			pos;

	arg_1 = get_first_arg(carriage, d);
	arg_2 = get_second_arg(carriage, d);
	arg_3 = d->arena[carriage->cursor_copy] - 1;
	if (is_valid_reg(carriage->cursor_copy, d) && arg_1 != 2147483648 \
		&& arg_2 != 2147483648)
	{
		pos = (carriage->cursor + arg_1 + arg_2) % MEM_SIZE;
		carriage->registrys[arg_3] = get_4_byte_value(d, pos);
		carriage->cursor = (carriage->cursor_copy + 1) % MEM_SIZE;
	}
	else
		ft_printf("{purple}error in and function\n"); // skip somewhere
}


/*
01 01 01 00 REG REG REG == 0x54 == 1 + 1 + 1 - tested
01 10 01 00 REG DIR REG == 0x64 == 1 + 2 + 1 - tested
10 01 01 00 DIR REG REG == 0x94 == 2 + 1 + 1 - tested
10 10 01 00 DIR DIR REG == 0xa4 == 2 + 2 + 1 - tested
11 01 01 00 IND REG REG == 0xd4 == 2 + 1 + 1 - tested
11 10 01 00 IND DIR REG == 0xe4 == 2 + 2 + 1 - tested
*/

static long long	get_first_arg(t_carriage *carriage, t_vm_data *d)
{
	int			res;
	int			pos;

	res = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	pos = (carriage->cursor + 2) % MEM_SIZE;
	if (((res == 0x54 && is_valid_reg((pos + 1) % MEM_SIZE, d)) || res == 0x64)\
		&& is_valid_reg(pos, d))
	{
		carriage->cursor_copy = (carriage->cursor + 3) % MEM_SIZE;
		return (carriage->registrys[d->arena[pos] - 1]);
	}
		
	else if ((res == 0x94 && is_valid_reg((pos + 2) % MEM_SIZE, d)) || res == 0xa4)
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


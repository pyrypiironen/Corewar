/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:35 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 12:47:36 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

int	is_valid_reg(int position, t_vm_data *d)
{
	int	ret;

	ret = 0;
	if (d->arena[position] > 0 && d->arena[position] <= REG_NUMBER)
		ret = 1;
	return (ret);
}

int	update_carry(int value)
{
	if (value == 0)
		return (1);
	return (0);
}

int	get_4_byte_value(t_vm_data *d, int position)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned char	fourth;
	int				value;

	first = d->arena[(position + 0) % MEM_SIZE];
	second = d->arena[(position + 1) % MEM_SIZE];
	third = d->arena[(position + 2) % MEM_SIZE];
	fourth = d->arena[(position + 3) % MEM_SIZE];
	value = (first << 24) + (second << 16) + (third << 8) + fourth;
	return (value);
}

int	get_2_byte_value(t_vm_data *d, int position, int idx)
{
	unsigned char	first;
	unsigned char	second;
	short			value;

	first = d->arena[(position + 0) % MEM_SIZE];
	second = d->arena[(position + 1) % MEM_SIZE];
	value = (first << 8) + second;
	if (idx)
		value = value % IDX_MOD;
	return ((int)value);
}

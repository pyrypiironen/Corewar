/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:35 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/13 14:07:19 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// Check if given registry is valid (return 1) or invalid (return 0).
int	is_valid_reg(int position, t_vm_data *d)
{
	if (d->arena[position] > 0 && d->arena[position] <= REG_NUMBER)
		return (1);
	return (0);
}

int	update_carry(int value)
{
	if (value == 0)
		return (1);
	return (0);
}

// Get values from given position and following three memory locations.
// Convert values to one integer and return it.
// Protected against negative 'position' parameter.
int	get_4_byte_value(t_vm_data *d, int position)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned char	fourth;
	int				value;

	if (position < 0)
		position = position % MEM_SIZE + MEM_SIZE;
	first = d->arena[(position + 0) % MEM_SIZE];
	second = d->arena[(position + 1) % MEM_SIZE];
	third = d->arena[(position + 2) % MEM_SIZE];
	fourth = d->arena[(position + 3) % MEM_SIZE];
	value = (first << 24) + (second << 16) + (third << 8) + fourth;
	return (value);
}

// Get values from given position and following  memory location.
// Convert values to one integer and return it. IDX_MOD is used if given
// parameter idx is not 0. Protected against negative 'position' parameter.
int	get_2_byte_value(t_vm_data *d, int position, int idx)
{
	unsigned char	first;
	unsigned char	second;
	short			value;
	
	if (position < 0)
		position = position % MEM_SIZE + MEM_SIZE;
	first = d->arena[(position + 0) % MEM_SIZE];
	second = d->arena[(position + 1) % MEM_SIZE];
	value = (first << 8) + second;
	if (idx)
		value = value % IDX_MOD;
	return ((int)value);
}

// Take integer value as a parameter and write it to the arena starting on given
// position.
void	int_to_arena(t_vm_data *d, int position, int value)
{
	d->arena[position] = (value & 0xff000000) >> 24;
	d->arena[(position + 1) % MEM_SIZE] = (value & 0x00ff0000) >> 16;
	d->arena[(position + 2) % MEM_SIZE] = (value & 0x0000ff00) >> 8;
	d->arena[(position + 3) % MEM_SIZE] = (value & 0x000000ff);
}

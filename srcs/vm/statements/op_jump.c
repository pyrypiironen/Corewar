/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:46:20 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 12:46:21 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

// This statement only takes an action, if carry flag is set to 1. If it is so,
// carriage cursor move to current position + <first arg> % IDX_MOD>.
void	op_jump(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	first;
	unsigned char	second;
	short			arg;
	
	first = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	second = d->arena[(carriage->cursor + 2) % MEM_SIZE];
	arg = ((first << 8) + second);
	if (carriage->carry)
	{
		carriage->cursor = move_cursor(carriage, arg % IDX_MOD);
		if (d->a_flag != -2)
			ft_printf("P      | zjmp %d OK\n", arg);
	}
	else
	{
		carriage->cursor = (carriage->cursor + 3) % MEM_SIZE;
		if (d->a_flag != -2)
			ft_printf("P      | zjmp %d FAILED\n", arg);
	}
}

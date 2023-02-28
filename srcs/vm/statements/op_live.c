/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:30:14 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/30 15:30:15 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

// Live statement. Carriage which performs the live statement is alive.
// Also if the number specified as an argument matches the number of the player,
// then it will consider that the player is alive.
void	op_live(t_carriage *carriage, t_vm_data *d)
{
	int	value;

	carriage->last_live = d->current_cycle;
	d->live_statements += 1;
	value = get_4_byte_value(d, (carriage->cursor + 1) % MEM_SIZE);
	value *= -1;
	if (value > 0 && value <= d->player_amount)
		d->winner = value;
	carriage->cursor = (carriage->cursor + 5) % MEM_SIZE;
}

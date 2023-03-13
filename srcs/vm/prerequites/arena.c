/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:40:06 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/23 14:40:08 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static void	plant_excode(t_vm_data *d, int location);

// Plant the contestants excodes on the arena.
void	fill_arena(t_vm_data *d)
{
	int	location;
	
	location = MEM_SIZE / d->player_amount;
	d->players = d->player_head;
	while (d->players)
	{
		plant_excode(d, location);
		d->players = d->players->next;
	}
}

// Plant one players excode on the arena.
static void	plant_excode(t_vm_data *d, int location)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = location * (d->players->id - 1);
	d->players->location = start;
	end = start + d->players->code_size;
	while (start < end)
	{
		d->arena[start] = d->players->excode[i];
		d->arena_color[start] = d->players->id;
		start++;
		i++;
	}
}

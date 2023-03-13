/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:58:10 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/12 17:58:11 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void	init_arena(t_vm_data *d);
static void	init_data_vm(t_vm_data *d);

// Initialize all necessary data before the game starst.
// This function is used by main.
void	init_core(int argc, char **argv, t_vm_data *d)
{
	init_data_vm(d);
	read_champs(argc, argv, d);
	fill_arena(d);
	init_carriages(d);
}

// Initialize the arena and array which points the color of every memory
// location when print the arena.
static void	init_arena(t_vm_data *d)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		d->arena[i] = 0;
		d->arena_color[i] = 0;
		i++;
	}
}

// Initialize data struct.
static void	init_data_vm(t_vm_data *d)
{
	init_arena(d);
	d->player_head = NULL;
	d->carriage_head = NULL;
	d->player_amount = 0;
	d->winner = 0;
	d->current_cycle = 0;
	d->cycles_to_die = CYCLE_TO_DIE;
	d->cycles_to_check = d->cycles_to_die;
	d->live_statements = 0;
	d->n_flag = 0;
	d->d_flag = -2;
	d->od_flag = -2;
	d->c_flag = -2;
	d->a_flag = -2;
}

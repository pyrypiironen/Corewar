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

void	init_core(int argc, char **argv, t_vm_data *d)
{
	init_data_vm(d);
	read_champs(argc, argv, d);
	fill_arena(d);
	init_carriages(d);


}

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

static void	init_data_vm(t_vm_data *d)
{
	init_arena(d);
	d->player_head = NULL;
	d->carriage_head = NULL;
	d->player_amount = 0;
	d->last_live = 0;
	d->cycles_to_die = CYCLE_TO_DIE;
	d->live_statements = 0;
	d->n_flag = 0;
}


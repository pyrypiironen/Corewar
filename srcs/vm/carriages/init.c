/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:39:35 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:37 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void	fill_carriage(t_vm_data *d);

// Allocate memory and initialize carriages for all players before
// the game will start.
void	init_carriages(t_vm_data *d)
{
	int			i;
	t_carriage	*carriage;

	i = 1;
	while (i <= d->player_amount)
	{
		carriage = (t_carriage *)malloc(sizeof(t_carriage));
		if (carriage == NULL)
			print_error("Malloc failed.", 0);
		d->players = d->player_head;
		while (d->players->id != i)
			d->players = d->players->next;
		carriage->next = d->carriage_head;
		d->carriage_head = carriage;
		fill_carriage(d);
		i++;
	}
}

// Initialize one carriage.
static void	fill_carriage(t_vm_data *d)
{
	int	i;
	
	i = 1;
	d->carriage_head->id = d->players->id;
	d->carriage_head->carry = 0;
	d->carriage_head->cursor = d->players->location;
	d->carriage_head->cursor_copy = 0;
	d->carriage_head->last_live = 0;
	d->carriage_head->statement = d->arena[d->players->location];
	d->carriage_head->to_execute = -1;			// Before first statement
	d->carriage_head->jump_size = -1;			// Check this
	d->carriage_head->registrys[0] = d->players->id * -1;
	while (i < REG_NUMBER)
		d->carriage_head->registrys[i++] = 1; // FOR TESTING
}

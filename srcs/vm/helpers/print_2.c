/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:28:52 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/17 13:11:43 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	print_winner(t_vm_data *d)
{
	d->players = d->player_head;
	while (d->players->id != d->winner)
		d->players = d->players->next;
	ft_printf("Contestant %d, \"%s\", has won !\n", \
	d->winner, d->players->name);
}

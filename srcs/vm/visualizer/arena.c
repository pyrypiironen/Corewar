/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:40:41 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/17 11:58:25 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

// Print arena on colors.
void	print_arena(t_vm_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		while (i < MEM_SIZE && j < 32)
		{
			ft_printf("%s%.2X\x1B[0m", g_color_tab[d->arena_color[i] % 5], \
			d->arena[i]);
			i++;
			j++;
			if (i % 2 == 0 && i < MEM_SIZE)
				ft_printf(" ");
		}
		ft_printf("\n");
	}
}

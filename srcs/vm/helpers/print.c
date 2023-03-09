/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:39:34 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/13 11:39:36 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	print_error(char *str, int usage)
{
	write(2, "ERROR: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	if (usage == 1)
		ft_printf("Usage: ./corewar [-dump nbr] [-n nbr] champ1.cor ...\n");
	exit(1);
}

void	print_dump(t_vm_data *d)
{
	int	i;
	int	j;

	i = 0;
	while(i < MEM_SIZE)
	{
		j = 0;
		while (i < MEM_SIZE && j < 32)
		{
			ft_printf("%.2x", d->arena[i]);
			i++;
			j++;
			if (j < 32)
				ft_printf(" ");
		}
		ft_printf("\n");
	}
	exit(0);
}

void	print_replica_dump(t_vm_data *d)
{
	int	i;
	int	j;

	i = 0;
	while(i < MEM_SIZE)
	{
		ft_printf("0x%.4x : ", i);
		j = 0;
		while (i < MEM_SIZE && j < 64)
		{
			ft_printf("%.2x", d->arena[i]);
			i++;
			j++;
			ft_printf(" ");
		}
		ft_printf("\n");
	}
	exit(0);
}

void	print_contestants(t_vm_data *d)
{
	int	i;

	i = 1;
	ft_printf("Introducing contestants...\n");
	
	while(i <= d->player_amount)
	{
		d->players = d->player_head;
		while (d->players->id != i)
			d->players = d->players->next;
		ft_printf("* Player %i, ", d->players->id);
		ft_printf("weighing %i bytes, ", d->players->code_size);
		ft_printf("\"%s\" ", d->players->name);
		ft_printf("(\"%s\") !\n", d->players->comment);
		i++;
	}
}

void	dump_info(t_vm_data *d)
{
	int	i;

	d->carriage = d->carriage_head;
	ft_printf("\nCycle: %i\n", d->current_cycle);
	ft_printf("Cycles to die: %i\n", d->cycles_to_die);
	ft_printf("Cycles to check: %i\n", d->cycles_to_check);
	ft_printf("Live statements: %i\n", d->live_statements);
	while (d->carriage)
	{
		i = 0;
		ft_printf("\nID: %i\n", d->carriage->id);
		ft_printf("Carry flag: %i\n", d->carriage->carry);
		ft_printf("Cursor location: %i\n", d->carriage->cursor);
		ft_printf("Statement: %.2X\n", d->carriage->statement);
		ft_printf("To execute:						\
		%i\n", d->carriage->to_execute);
		ft_printf("Last live: %i\n", d->carriage->last_live);
		while (i < 16)
		{
			ft_printf("Registry %i: %i\n", i + 1, d->carriage->registrys[i]);
			i++;
		}
		d->carriage = d->carriage->next;
	}
	exit(0);
}
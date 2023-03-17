/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:14:16 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/17 12:04:56 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

static void	execute_statements(t_vm_data *d);
static void	check_carriage(t_vm_data *d);
static void	read_statement(t_vm_data *d);

// Main function to run the game in virtual machine. Check flags, excecute
// statements if necessary and check the carriages.
void	play_the_game(t_vm_data *d)
{
	while (d->carriage_head)
	{
		if (d->a_flag != -2)
			ft_printf("It is now cycle %d\n", d->current_cycle + 1);
		if (d->d_flag == d->current_cycle || \
			d->a_flag == d->current_cycle)
			print_dump(d);
		else if (d->od_flag == d->current_cycle)
			print_replica_dump(d);
		else if (d->c_flag == d->current_cycle)
			dump_info(d);
		d->current_cycle += 1;
		d->cycles_to_check -= 1;
		execute_statements(d);
		if (d->cycles_to_check <= 0)
			check(d);
	}
}

// Run the loop that check every carriages, read and execute the statements
// if necessary, and remove dead carriages.
static void	execute_statements(t_vm_data *d)
{
	d->carriage = d->carriage_head;
	while (d->carriage)
	{
		check_carriage(d);
		d->carriage = d->carriage->next;
	}
}

// Read statement if there is no statement waiting to execute. If there is,
// then countdown and execute the statement on right cycle.
static void	check_carriage(t_vm_data *d)
{
	static const t_op	dispatcher[16] = {op_live, op_ld, op_st, op_add, \
	op_sub, op_and, op_or, op_xor, op_jump, op_ldi, op_sti, op_fork, op_lld, \
	op_lldi, op_lfork, op_aff
	};

	d->carriage->to_execute -= 1;
	if (d->carriage->to_execute < 0)
		read_statement(d);
	else if (d->carriage->to_execute == 0)
	{
		dispatcher[d->carriage->statement](d->carriage, d);
		if (d->a_flag != -2)
			ft_printf("Carriage position: %d\n", d->carriage->cursor);
	}
}

// Read new statement and init all its necessary data to the carriage.
static void	read_statement(t_vm_data *d)
{
	static const int	to_execute[16] = \
	{10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

	d->carriage->statement = d->arena[d->carriage->cursor] - 1;
	if (d->carriage->statement < 16 && d->carriage->statement >= 0)
		d->carriage->to_execute = to_execute[d->carriage->statement] - 1;
	else
		d->carriage->cursor = (d->carriage->cursor + 1) % MEM_SIZE;
}

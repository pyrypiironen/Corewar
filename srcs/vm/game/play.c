


# include "../../../includes/vm.h"

static void	execute_statements(t_vm_data *d);
static void	check_carriage(t_vm_data *d);
static void	read_statement(t_vm_data *d);


void	play_the_game(t_vm_data *d)
{
	while (d->carriage_head)
	{
		if (d->d_flag == d->current_cycle)
			print_dump(d);
		else if (d->od_flag == d->current_cycle)
			print_replica_dump(d);
		else if (d->c_flag == d->current_cycle)
			dump_info(d);
		d->current_cycle += 1;
		d->cycles_to_check -= 1;
		execute_statements(d);
		//write(1, "execute statements out\n", 24);
		if (d->cycles_to_check <= 0)
			check(d);
	}
}

static void	execute_statements(t_vm_data *d)
{
	//write(1, "execute statements in\n", 24);
	d->carriage = d->carriage_head;
	while (d->carriage)
	{
		check_carriage(d);
		d->carriage = d->carriage->next;
	}

}

static void	check_carriage(t_vm_data *d) // seg fault 
{
	//write(1, "Check carriage in\n", 18);
	d->carriage->to_execute -= 1;
	if (d->carriage->to_execute < 0)
		read_statement(d);
	else if (d->carriage->to_execute == 0)
	{
		//write(1, "Dispatch\n", 10);
		//printf("Statement: %d\n", d->carriage->statement);
		g_dispatcher[d->carriage->statement](d->carriage, d);
		//write(1, "Dispatch done\n", 15);
	}
	//write(11, "Check carriage out\n", 18);
}

static void	read_statement(t_vm_data *d)
{
	//write(1, "read statement in\n", 18);
	static const int	to_execute[16] = \
	{10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

	d->carriage->statement = d->arena[d->carriage->cursor] - 1;
	if (d->carriage->statement < 16 && d->carriage->statement >= 0)
		d->carriage->to_execute = to_execute[d->carriage->statement] - 1;// Is -1 correct?
	else
		d->carriage->cursor = (d->carriage->cursor + 1) % MEM_SIZE;
	//write(1, "read statement out\n", 20);
}
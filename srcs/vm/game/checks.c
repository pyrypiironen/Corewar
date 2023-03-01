# include "../../../includes/vm.h"

static void	remove_dead(t_vm_data *d);
static int	is_dead(t_vm_data *d, t_carriage *carriage);

// 
void	check(t_vm_data *d)
{
	d->check_count += 1;
	if(d->check_count == MAX_CHECKS || d->live_statements >= NBR_LIVE)
	{
		d->cycles_to_die -= CYCLE_DELTA;
		d->check_count = 0;
	}
	d->cycles_to_check = d->cycles_to_die;
	d->live_statements = 0;
	remove_dead(d);
}

// Run through the carriages and remove dead ones.
static void	remove_dead(t_vm_data *d)
{
	t_carriage	*tmp;

	d->carriage = d->carriage_head;
	while (is_dead(d, d->carriage))
	{
		d->carriage_head = d->carriage->next;
		free(d->carriage);
		d->carriage = d->carriage_head;
	}
	while(d->carriage && d->carriage->next)
	{
		if (is_dead(d, d->carriage->next))
		{
			tmp = d->carriage->next;
			d->carriage->next = d->carriage->next->next;
			free(tmp);
		}
		else
			d->carriage = d->carriage->next;
	}
}

// Check if carriage is dead. Return 1 if it is dead and 0 if it is alive.
static int	is_dead(t_vm_data *d, t_carriage *carriage)
{
	if(carriage && (d->cycles_to_die <= d->current_cycle - carriage->last_live))
		return (1);
	return (0);
}
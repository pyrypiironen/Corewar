

#include "vm.h"

void	print_winner(t_vm_data *d)
{
	d->players = d->player_head;
	while (d->players->id != d->winner)
		d->players = d->players->next;
	ft_printf("Contestant %d, \"%s\", has won !\n", \
	d->winner, d->players->name);
}
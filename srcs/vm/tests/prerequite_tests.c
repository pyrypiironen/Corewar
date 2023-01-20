// Header

#include "../../../includes/vm.h"

// Print every champions basic data.
void	print_champs(t_vm_data *d)
{
	t_player	*champ;
	int				i;

	champ = d->player_head;
	while (champ)
	{
		i = 0;
		ft_printf("{blue}Name: ");
		ft_printf("{yellow}%s\n", champ->name);
		ft_printf("{blue}ID: ");
		ft_printf("{yellow}%i\n", champ->id);
		ft_printf("{blue}Code size: ");
		ft_printf("{yellow}%i\n", champ->code_size);
		ft_printf("{blue}Comment: ");
		ft_printf("{yellow}%s\n", champ->comment);
		ft_printf("{blue}Execution code: ");
		while (i < champ->code_size)
		{
			ft_printf("%.2X", champ->excode[i]);
			i++;
			if (i == champ->code_size)
				break ;
			ft_printf("%.2X ", champ->excode[i]);
			i++;
		}
		ft_printf("\n");
	champ = champ->next;
	}
	ft_printf("{blue}Player amount: %i\n", d->player_amount);
}

void	print_arena(t_vm_data *d)
{
	int	i;
	int	j;

	i = 0;
	while(i < MEM_SIZE)
	{
		j = 0;
		while (i < MEM_SIZE && j < 32)
		{
			ft_printf("%s%.2X\x1B[0m", color_tab[d->arena_color[i] % 5], \
			d->arena[i]);
			i++;
			j++;
			if (i % 2 == 0 && i < MEM_SIZE)
				ft_printf(" ");
		}
		ft_printf("\n");
	}
}

void	print_carriages(t_vm_data *d)
{
	t_carriage	*carriage;
	int			i;

	carriage = d->carriage_head;
	while (carriage)
	{
		i = 0;
		ft_printf("{blue}\nID: ");
		ft_printf("{yellow}%i\n", carriage->id);
		ft_printf("{blue}Carry flag: ");
		ft_printf("{yellow}%i\n", carriage->carry);
		ft_printf("{blue}Cursor location: ");
		ft_printf("{yellow}%i\n", carriage->cursor);
		ft_printf("{blue}Statement: ");
		ft_printf("{yellow}%.2X\n", carriage->statement);
		ft_printf("{blue}To execute: ");
		ft_printf("{yellow}%i\n", carriage->to_execute);
		ft_printf("{blue}Jump size: ");
		ft_printf("{yellow}%i\n", carriage->jump_size);
		while (i < 16)
		{
			ft_printf("Registry %i: %i\n", i, carriage->registrys[i]);
			i++;
		}
		carriage = carriage->next;
	}
}
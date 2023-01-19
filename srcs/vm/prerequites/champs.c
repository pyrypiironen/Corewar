/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:00:07 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/12 19:00:10 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

// Test function with short (< 4) names
int	is_champ(char *argv, t_vm_data *d)
{
	int			len;
	t_player	*champ;	

	len = ft_strlen(argv);
	if(ft_strcmp(&(argv[len - 4]), ".cor") != 0)
		return (0); // no champ
	//Create champ:
	champ = (t_player *)malloc(sizeof(t_player));
	if (champ == NULL)
		print_error("Malloc failed.", 0);
	init_champ(d, champ, argv);


	return (1);
}

void	init_champ(t_vm_data *d, t_player *champ, char *file)
{
	int	fd;
	
	champ->id = d->n_flag; //if this is 0, change after to first available number
	d->n_flag = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Invalid file.", 0);
	read_magic(fd);
	read_name(champ, fd);
	skip_nulls(fd);
	read_excode_size(champ, fd);
	read_comment(champ, fd);
	skip_nulls(fd);
	read_excode(champ, fd);
	if (close(fd) == -1)
		print_error("Closing file description failed.", 0);
	champ->next = d->player_head;
	d->player_head = champ;
	d->player_amount += 1;
	if (d->player_amount == 5)
		print_error("Too many players. Max 4 players allowed.", 0);
}

void	init_ids(t_vm_data *d)
{
	int	id;

	id = d->player_amount;
	d->players = d->player_head;
	while (id > 0)
	{
		while (d->players && d->players->id != 0)
			d->players = d->players->next;
		if (d->players == NULL)
			break ;
		if (!check_id(d->player_head, id))
		{
			d->players->id = id;
			d->players = d->players->next;
		}
		id--;
	}
}

int	check_id(t_player *champ, int id)
{
	while (champ != NULL)
	{
		if (champ->id == id)
			return (1);
		champ = champ->next;
	}
	return (0);
}

void	id_error_check(t_vm_data *d)
{
	t_player *tmp;

	if (d->player_amount > MAX_PLAYERS)
		print_error("Wrong usage. Player number can't be bigger than \
MAX_PLAYERS.", 1);
	d->players = d->player_head;
	while (d->players)
	{
		tmp = d->players->next;
		while (tmp)
		{
			if (d->players->id == tmp->id)
				print_error("Wrong usage. Duplicate player numbers.", 1);
			tmp = tmp->next;
		}
		if (d->players->id > d->player_amount)
		{
			ft_printf("{red}id: %d || amount: %d\n", d->players->id, d->player_amount);
			print_error("Wrong usage. Player number can't be bigger than \
player amount.", 1);
		}
		d->players = d->players->next;
	}

}


// Examble of champions code
// https://raw.githubusercontent.com/VBrazhnik/Corewar/master/wiki_resources/bytecode.svg
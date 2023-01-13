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

// static void	init_champ(t_vm_data *d, t_player *champ);

// Test function with short (< 4) names
int	is_champ(t_vm_data *d, char *argv)
{
	int			len;
	t_player	*champ;	

	len = ft_strlen(argv);
	if(ft_strcmp(*(argv + (len - 4), ".cor")) != 0)
		return (0); // no champ
	//Create champ:
	champ = (t_player)malloc(sizeof(t_player));
	if (champ == NULL)
		print_error("Malloc failed.", 0);
	init_champ(d, champ);
	



	return (1);
}


// static void	init_champ(t_vm_data *d, t_player *champ);
// {
// 	d->id = d->n_flag; //if this is 0, change after to first available number
// 	d->n_flag = 0;
// 	// Followed functions do not exist yet
// 	read_magic(d, champ);
// 	read_name(d, champ);
// 	// skip nulls
// 	read_exec_size(d, champ);
// 	read_comment(d, champ);
// 	// skip nulls
// 	read_exec(d, champ);
// }

// Examble of champions code
// https://raw.githubusercontent.com/VBrazhnik/Corewar/master/wiki_resources/bytecode.svg
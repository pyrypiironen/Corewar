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

static void	init_champ(t_vm_data *d, t_player *champ, char *file);

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


static void	init_champ(t_vm_data *d, t_player *champ, char *file)
{
	int	fd;
	
	champ->id = d->n_flag; //if this is 0, change after to first available number
	d->n_flag = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Invalid file.", 0);
	read_magic(fd);
		// Followed functions do not exist yet
	// read_name(d, champ);
	// // skip nulls
	// read_exec_size(d, champ);
	// read_comment(d, champ);
	// // skip nulls
	// read_exec(d, champ);
	// if (close(fd) == -1)
	// 	print_error("Closing file description failed.", 0);
}

void	read_magic(int fd)
{
	unsigned char	buf[4];
	int				total;

	if (read(fd, &buf, 4) != 4)
		print_error("Invalid file.", 0);
	total = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
	if (total != COREWAR_EXEC_MAGIC)
		print_error("Invalid file.", 0);
}


// Examble of champions code
// https://raw.githubusercontent.com/VBrazhnik/Corewar/master/wiki_resources/bytecode.svg
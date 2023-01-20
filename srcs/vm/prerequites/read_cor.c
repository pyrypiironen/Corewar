/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:56:30 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/13 12:56:31 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

// Read magic header from champions .cor file and check the validity.
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

// Read name of champion from .cor file and check the validity.
void	read_name(t_player *champ, int fd)
{
	if (read(fd, champ->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		print_error("Invalid file.", 0);
	champ->name[PROG_NAME_LENGTH] = '\0';
}

// Skip null part of champions .cor file.
void	skip_nulls(int fd)
{
	unsigned char	buf[4];
	int				i;

	i = 0;
	if (read(fd, &buf, 4) != 4)
		print_error("Invalid file.", 0);
	while (i < 4)
	{
		if (buf[i])
			print_error("Invalid file.", 0);
		i++;
	}
}

// Read execution code size of champion from .cor file and check the validity.
void	read_excode_size(t_player *champ, int fd)
{
	unsigned char	buf[4];

	if(read(fd, &buf, 4) != 4)
		print_error("Invalid file.", 0);
	champ->code_size = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];

}

// Read comment of champion from .cor file and check the validity.
void	read_comment(t_player *champ, int fd)
{
	if (read(fd, champ->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		print_error("Invalid file.", 0);
	champ->comment[COMMENT_LENGTH] = '\0';

}
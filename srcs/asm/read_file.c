/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:28 by abackman          #+#    #+#             */
/*   Updated: 2023/01/12 16:47:45 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	init_head(t_asm *d, int fd)
{
	d->head.prog_size = (unsigned int) lseek(fd, 0, SEEK_END);
	// return offset to start?
	//CHECK LATER< IF AT ALL -- if (d->head.prog_size == -1 || d->head.prog_name > CHAMP_MAX_SIZE)
	//	exit_asm(d, "ERROR: invalid program size");
	d->head.magic = COREWAR_EXEC_MAGIC; // change to BIG ENDIAN
	ft_bzero(d->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(d->head.comment, COMMENT_LENGTH + 1);
}

static void	get_prog_name(t_asm *d)
{
	if (!d)
		return ;
	//use buffer or fd?
}

static void	get_comment(t_asm *d)
{
	if (!d)
		return ;
	// use buffer or fd?
}

static void	validate_file(t_asm *d, char *name)
{
	int	fd;

	fd = 0;
	if (!name)
		exit_asm(d, "ERROR: invalid file.");
	fd = open(name, O_RDONLY);
	if (fd < 1)
		exit_asm(d, "ERROR: invalid file.");
	init_head(d, fd);
	if (read(fd, d->buf, d->head.prog_size) == -1)
		exit_asm(d, "ERROR: could not read champion source file.");
	get_prog_name(d);
	get_comment(d);
	// check/copy name and comment
}

void	read_file(t_asm *d, int ac, char **av)
{
	int	count;

	count = 0;
	validate_file(d, av[ac - 1]);
}
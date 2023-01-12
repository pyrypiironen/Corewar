/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:28 by abackman          #+#    #+#             */
/*   Updated: 2023/01/12 18:38:38 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

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

static void	validate_file_name(t_asm *d, char *name)
{
	char	*extension;

	extension = ft_strrchr(name, '.');
	if (!extension)
		exit_asm(d, "ERROR: invalid file name.");
	if (ft_strcmp(extension, ".s"))
		exit_asm(d, "ERROR: invalid file extension.");
	if (!ft_strcmp(name, extension))
		exit_asm(d, "ERROR: invalid file name.");
}

static void	validate_file(t_asm *d, char *name)
{
	int		fd;

	fd = 0;
	if (!name)
		exit_asm(d, "ERROR: invalid file.");
	fd = open(name, O_RDONLY);
	if (fd < 1)
		exit_asm(d, "ERROR: could not open file.");
	validate_file_name(d, name);
	if (read(fd, d->buf, d->head.prog_size) == -1)
		exit_asm(d, "ERROR: could not read champion source file.");
	d->fd = fd;
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
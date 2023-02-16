/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:28 by abackman          #+#    #+#             */
/*   Updated: 2023/02/16 15:16:32 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	validate_file_name(t_asm *d, char *name)
{
	char	*extension;

	extension = ft_strrchr(name, '.');
	if (!extension)
		exit_asm(d, "ERROR: invalid file name.\n");
	if (ft_strcmp(extension, ".s"))
		exit_asm(d, "ERROR: invalid file extension.\n");
}

static void	validate_file(t_asm *d, char *name)
{
	off_t	start;
	off_t	end;

	start = 0;
	end = 0;
	if (!name)
		exit_asm(d, FILE_ERR);
	d->fd = open(name, O_RDWR);
	ft_printf("Opening directory: %i\n", d->fd);
	if (d->fd < 1)
		exit_asm(d, "ERROR: could not open file for reading.\n");
	validate_file_name(d, name);
	start = lseek(d->fd, 0, SEEK_SET);
	end = lseek(d->fd, start, SEEK_END);
	lseek(d->fd, start, SEEK_SET);
	if (start == -1 || end == -1 || start == end)
		exit_asm(d, FILE_ERR);
	d->buf = ft_strnew(end);
	if (d->buf == NULL)
		exit_asm(d, MALLOC_ERR);
	read(d->fd, d->buf, end);
	lseek(d->fd, start, SEEK_SET);
}

void	validate(t_asm *d, int ac, char **av)
{
	validate_file(d, av[ac - 1]);
}

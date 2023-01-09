/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:28 by abackman          #+#    #+#             */
/*   Updated: 2023/01/09 17:05:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	parse_file(t_asm *d, char *name)
{
	int	fd;

	fd = 0;
	if (!name)
		exit_asm(d, "ERROR: invalid file.");
	fd = open(name, O_RDONLY);
	if (fd < 1)
		exit_asm(d, "ERROR: invalid file.");
}

void	read_file(t_asm *d, int ac, char **av)
{
	int	count;

	count = 0;
	while (++count < ac)
		parse_file(d, av[count - 1]);
}
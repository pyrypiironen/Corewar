/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:42 by abackman          #+#    #+#             */
/*   Updated: 2023/01/20 16:04:33 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	exit_asm(t_asm *d, char *str)
{
	free_asm(d);
	ft_printf(str);
	exit(1);
}

void	parse_flags(t_asm *d, char *str)
{
	if (!ft_strcmp(str, "-d"))
		d->debug = true;
	else
		exit_asm(d, "ERROR: invalid flag.");
}

int	main(int ac, char **av)
{
	t_asm	d;
	int		i;

	i = 0;
	if (ac == 1)
		exit_asm(NULL, "ERROR: too few arguments.");
	while (++i < (ac - 1))
		parse_flags(&d, av[i]);
	init_asm(&d, ac, av);
	validate(&d, ac, av);
	read_file(&d);
	close(d.fd);
	//write_file(&d);
	return (0);
}

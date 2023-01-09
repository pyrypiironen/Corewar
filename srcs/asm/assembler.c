/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:42 by abackman          #+#    #+#             */
/*   Updated: 2023/01/09 17:18:35 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	free_asm(t_asm	*d)
{
	if (d == NULL)
		return ;
}

void	exit_asm(t_asm *d, char *str)
{
	if (d)
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

void	init_asm(t_asm *d, int ac, char **av)
{
	int	i;

	i = 0;
	d->n_players = 0;
	d->debug = false;
	while (++i < (ac - 1))
		parse_flags(d, av[i]);
}

int	main(int ac, char **av)
{
	t_asm	d;

	if (ac == 1)
		exit_asm(NULL, "ERROR: too few arguments.");
	init_asm(&d, ac, av);
	read_file(&d, av[i]);
}

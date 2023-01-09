/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:42 by abackman          #+#    #+#             */
/*   Updated: 2023/01/09 15:11:11 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	free_asm(t_asm	*d)
{
	if (d == NULL)
		return ;
	free(d);
	d = NULL;
}

void	exit_asm(t_asm *d, char *str)
{
	if (d)
		free_asm(d);
	ft_printf(str);
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		exit_asm(NULL, "Error:·too·few·arguments.");
}

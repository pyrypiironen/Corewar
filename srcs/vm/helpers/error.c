/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:39:34 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/13 11:39:36 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	print_error(char *str, int usage)
{
	write(2, "ERROR: ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	if (usage == 1)
		ft_printf("Usage: ./corewar [-dump nbr] [-n nbr] champ1.cor ...\n");
	exit(1);
}

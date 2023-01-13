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

static void	put_error(char *str);

void	print_error(char *str, int usage)
{
	ft_printf("{red}ERROR: ");
	ft_printf("{red}%s\n", str);
	if (usage == 1)
		ft_printf("Usage: ./corewar diid diidididid\n") // write correct message
	put_error(str);
	exit(1);
}

// Write error messages to standard error (stderr stream).
// Do not handle usage messages yet.
static void	put_error(char *str)
{
	if (str == NULL)
		return ;
	write(2, "ERROR: ", 7);
	while (*str)
	{
		write(2, &(str), 1);
		str++;
	}
	write(2, "\n", 1);
}

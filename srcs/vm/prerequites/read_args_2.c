/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:03 by mjokela           #+#    #+#             */
/*   Updated: 2023/03/13 17:56:04 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

// Return the information if there is a flag which value is true or false.
int	is_bare_flag(t_vm_data *d, char *argv)
{
	if (ft_strcmp(argv, "-b") == 0)
	{
		d->b_flag = 1;
		return (1);
	}
	return (0);
}


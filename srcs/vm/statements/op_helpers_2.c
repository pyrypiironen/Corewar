/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:38:56 by mjokela           #+#    #+#             */
/*   Updated: 2023/02/01 15:39:01 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

int	count_jump_size(t_carriage *carriage, t_vm_data *d, int	dir_size, int args)
{
	int	ret;
	int	i;
	unsigned char	code;
	unsigned char	tmp;

	ret = 1;
	i = 0;
	code = d->arena[(carriage->cursor + 1)  % MEM_SIZE];
	code = code >> (2 + 2 * (3 - args));
	while(i < 3)
	{
		tmp = code & 3;
		if (tmp == 1)
			ret += 1;
		else if (tmp == 3 || (tmp == 2 && dir_size == 2))
			ret += 2;
		else if (tmp == 2)
			ret += 4;
		code = code >> 2;
		i++;
	}
	return (ret);
}
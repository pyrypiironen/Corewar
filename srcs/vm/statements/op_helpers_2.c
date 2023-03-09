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

// Count jump size based on argument types.
int	count_jump_size(t_carriage *carriage, t_vm_data *d, int	dir_size, int args)
{
	int	ret;
	int	i;
	unsigned char	code;
	unsigned char	tmp;

	ret = 2;
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

// Protect cursor movement against negative value and getting out of the arena.
// Return is new location of cursor, not the change.
int	move_cursor(t_carriage *carriage, int arg)
{
	if (carriage->cursor + arg >= 0)
		return ((carriage->cursor + arg) % MEM_SIZE);
	else
		return (MEM_SIZE + (carriage->cursor + arg) % MEM_SIZE);
}

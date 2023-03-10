/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:25:30 by abackman          #+#    #+#             */
/*   Updated: 2023/03/10 15:56:59 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Gets the location of the statement that the label points to, assigns it as
** the value of the corresponding argument.
*/

static void	add_label_values(t_asm *d)
{
	t_stat	*tmp;
	t_lab	*tmplab;
	char	*name;
	size_t	i;

	tmp = d->statements;
	while (tmp)
	{
		i = -1;
		while (++i < (size_t)g_op_tab[tmp->opcode].expected_arg_count)
		{
			name = tmp->arglabel[i];
			if (name)
			{
				tmplab = get_label(d, name, ft_strlen(name));
				if (!tmplab || !tmplab->statement)
					tmp->args[i] = d->code_size - tmp->loc;
				else
				{
					tmp->args[i] = tmplab->statement->loc - tmp->loc;
				}
			}
		}
		tmp = tmp->next;
	}
}

/*
** Calculates the result code.
*/

static size_t	calculate_rescode(t_stat *cur)
{
	cur->rescode = cur->argtypes[0] << 6;
	cur->rescode |= cur->argtypes[1] << 4;
	cur->rescode |= cur->argtypes[2] << 2;
	return (1);
}

/*
** Calculates the result code and the size of the statement.
*/

static size_t	calculate_statement_size(t_stat *cur)
{
	size_t	ret;
	uint8_t	i;
	uint8_t	dirsize;

	ret = 1;
	i = 0;
	dirsize = 4;
	if (cur->has_res == true)
		ret += calculate_rescode(cur);
	if (cur->opcode > 7 && cur->opcode < 15 && cur->opcode != 12)
		dirsize = 2;
	while (i < g_op_tab[cur->opcode].expected_arg_count)
	{
		if (cur->argtypes[i] == IND)
			ret += IND_SIZE;
		else if (cur->argtypes[i] == DIR)
			ret += dirsize;
		else
			ret += 1;
		i++;
	}
	return (ret);
}

/*
** Makes the appropriate calculations for each statement, their size and
** argument type code. Also calculates the values of labels.
*/

void	translate_calculations(t_asm *d)
{
	size_t	size;
	t_stat	*tmp;

	tmp = d->statements;
	tmp->loc = 0;
	while (tmp)
	{
		size = 0;
		size = calculate_statement_size(tmp);
		d->code_size += size;
		if (tmp->next)
			tmp->next->loc = d->code_size;
		tmp = tmp->next;
	}
	add_label_values(d);
}

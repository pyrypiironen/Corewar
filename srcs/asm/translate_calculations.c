/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:25:30 by abackman          #+#    #+#             */
/*   Updated: 2023/02/14 15:24:48 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static size_t	calculate_rescode(t_stat *cur)
{
	cur->rescode = cur->argtypes[0] << 6;
	cur->rescode |= cur->argtypes[1] << 4;
	cur->rescode |= cur->argtypes[2] << 2;
	ft_printf("calculate rescode [%u] [%x]\n", cur->opcode + 1, cur->rescode);
	return (1);
}

static size_t	calculate_statement_size(t_stat *cur)
{
	size_t	ret;
	uint8_t	i;
	uint8_t	dirsize;

	ret = 1;
	i = 0;
	dirsize = 4;
	if (cur->has_res)
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
	ft_printf("SIZE %u\n", ret);
	return (ret);
}

void	translate_calculations(t_asm *d)
{
	size_t	size;
	t_stat	*tmp;

	tmp = d->statements;
	while (tmp)
	{
		size = 0;
		size = calculate_statement_size(tmp);
		if (tmp->next)
			tmp->next->location = size;
		d->code_size += size;
		tmp = tmp->next;
	}
	ft_printf("code_size: %u | %x\n", d->code_size, d->code_size);
}
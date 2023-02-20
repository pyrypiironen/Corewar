/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:25:30 by abackman          #+#    #+#             */
/*   Updated: 2023/02/20 20:13:02 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/* static void	print_unref_labels(t_asm *d)
{
	t_lab	*tmplab;
	size_t	i;
	
	i = 0;
	while (i < d->n_labels)
	{
		tmplab = d->labels[i];
		while (tmplab)
		{
			if (!tmplab->statement && tmplab->name)
				ft_printf("%s\n", tmplab->name);
			tmplab = tmplab->next;
		}
		i++;
	}
} */

static void	add_label_values(t_asm *d)
{
	t_stat	*tmp;
	t_lab	*tmplab;
	char	*name;
	size_t	i;

	tmp = d->statements;
	while (tmp)
	{
		i = 0;
		while (i < (size_t)g_op_tab[tmp->opcode].expected_arg_count)
		{
			name = tmp->arglabel[i];
			if (name)
			{
				tmplab = get_label(d, name, ft_strlen(name));
				//ft_printf("Calc - %s\n", name);
				//if (tmplab)
				//	ft_printf("\t[%s]\n", tmplab->name);
				if (!tmplab || !tmplab->statement)
					tmp->args[i] = d->code_size - tmp->loc;
				else
				{
					tmp->args[i] = tmplab->statement->loc - tmp->loc;
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static size_t	calculate_rescode(t_stat *cur)
{
	cur->rescode = cur->argtypes[0] << 6;
	cur->rescode |= cur->argtypes[1] << 4;
	cur->rescode |= cur->argtypes[2] << 2;
	//ft_printf("rescode: %x\n", cur->rescode);
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
	//ft_printf("calculate statement sizes, has res: %u\n", cur->has_res);
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

void	translate_calculations(t_asm *d)
{
	size_t	size;
	t_stat	*tmp;

	//ft_putstr("translate_calculations\n");
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
	//ft_printf("code size: %x\n", d->code_size);
	add_label_values(d);
}
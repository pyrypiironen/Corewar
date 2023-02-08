/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_statement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/08 16:49:23 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static t_stat	*init_statement(t_asm *d, t_oken *cur)
{
	t_stat	*new;
	uint8_t	i;

	i = 0;
	new = (t_stat *)malloc(sizeof(t_stat *));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->label = NULL;
	new->opcode = 0;
	ft_bzero(new->args, 3 * sizeof(int));
	ft_bzero(new->argtypes, 3 * sizeof(uint8_t));
	new->cur_arg = 0;
	new->valid = false;
	while (i < 16)
	{
		if (!ft_strcmp(cur->str, g_op_tab[i].instruction))
			break ;
		i++;
	}
	new->opcode = i;
	ft_printf("INIT_STATEMENT i: %i, %p\n", i, new);
	/* new->op = g_op_tab[i];
	if (new->op.instruction)
		memdel_exit_asm(d, new, NULL); */
	return (new);
}

static void	add_statement_to_labels(t_asm *d, t_stat *new)
{
	int		i;
	t_lab	*tmp;

	i = -1;
	while (++i < (int)d->n_labels)
	{
		tmp = d->labels[i];
		while (tmp)
		{
			if (!tmp->statement)
				tmp->statement = new;
			tmp = tmp->next;
		}
	}
}

void	save_statement(t_asm *d, t_oken *cur, t_oken *prev)
{
	t_stat	*new;
	t_stat	*tmp;

	if (!cur && !prev)
		error_asm(d, NULL, -1);
	tmp = d->statements;
	new = init_statement(d, cur);
	ft_printf("Save_statement__\n");
	if (d->unref_labels)
	{
		add_statement_to_labels(d, new);
		return ;
	}
	d->tail_statement = new;
	if (!tmp)
	{
		d->statements = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	save_label(t_asm *d, t_oken *cur, t_oken *prev)
{
	t_lab	*new;

	new = (t_lab *)malloc(sizeof(t_lab *));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->name = cur->str;
	if (cur->next && cur->next->type == OP)
	{
		new->line = cur->next->row;
		new->start = cur->next->col;
	}
	else if (cur->next && cur->next->next && cur->next->next->type == OP)
	{
		new->line = cur->next->next->row;
		new->start = cur->next->next->col;
	}
	else
		d->unref_labels = true;
	add_label_to_table(d, new);
	if (!cur && !prev)
		error_asm(d, NULL, -1);
}

void	token_to_statement(t_asm *d, t_oken *cur, t_oken *prev)
{
	ft_printf("Save statement/label__\n");
	if (!d->head.prog_name[0] || !d->head.comment[0])
		asm_token_error(d, cur, STX_ERR);
	if (cur->type == OP)
		save_statement(d, cur, prev);
	else if (cur->type == LABEL)
		save_label(d, cur, prev);
	//ft_printf("Save statement/label__\n");
}
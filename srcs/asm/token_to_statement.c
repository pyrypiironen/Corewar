/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_statement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/28 14:28:38 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static t_stat	*init_statement(t_asm *d, t_oken *cur)
{
	t_stat	*new;
	int8_t	i;

	i = -1;
	new = (t_stat *)malloc(sizeof(t_stat));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->label = NULL;
	new->opcode = 0;
	new->rescode = 0;
	ft_bzero((void *)new->args, 3);
	ft_bzero((void *)new->argtypes, 3);
	ft_bzero((void *)new->arglabel, 3 * sizeof(char *));
	new->cur_arg = 0;
	new->loc = 0;
	new->valid = false;
	new->has_res = true;
	while (++i < 16)
	{
		if (!ft_strcmp(cur->str, g_op_tab[i].instruction))
			break ;
	}
	new->opcode = i;
	return (new);
}

void	add_statement_to_labels(t_asm *d, t_stat *new)
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
	d->unref_labels = false;
}

void	save_statement(t_asm **d, t_oken *cur, t_oken *prev)
{
	t_stat	*new;
	t_stat	*tmp;

	if (!cur && !prev)
		error_asm(*d, NULL, -1);
	if ((*d)->tail_statement && (*d)->tail_statement->valid == false)
		asm_token_error(*d, cur, ARGCOUNT_ERR);
	tmp = (*d)->statements;
	new = init_statement(*d, cur);
	if (new->opcode == 0 || new->opcode == 8 || new->opcode == 11 \
	|| new->opcode == 14)
		new->has_res = false;
	(*d)->tail_statement = new;
	if ((*d)->unref_labels)
		add_statement_to_labels(*d, new);
	if (!tmp)
	{
		(*d)->statements = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	save_label(t_asm *d, t_oken *cur, t_oken *prev)
{
	t_lab	*new;

	new = (t_lab *)malloc(sizeof(t_lab));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->statement = NULL;
	new->line = 0;
	new->start = 0;
	new->bytes = 0;
	new->name = ft_strsub(cur->str, 0, ft_strlen(cur->str) - 1);
	if (!new->name)
		memdel_exit_asm(d, new, MALLOC_ERR);
	d->unref_labels = true;
	add_label_to_table(d, new);
	if (!cur && !prev)
		error_asm(d, NULL, -1);
}

void	token_to_statement(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (!d->head.prog_name[0] || !d->head.comment[0])
		asm_token_error(d, cur, STX_ERR);
	if (cur->type == OP)
		save_statement(&d, cur, prev);
	else if (cur->type == LABEL)
		save_label(d, cur, prev);
}

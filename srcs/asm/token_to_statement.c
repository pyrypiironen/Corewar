/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_statement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/07 17:12:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

//static void	syntax_checker()
/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for basic errors.
*/


void	save_argument(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (!cur && !prev)
		error_asm(d, NULL, -1);
}

void	save_statement(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (!cur && !prev)
		error_asm(d, NULL, -1);
}

void	save_label(t_asm *d, t_oken *cur, t_oken *prev)
{
	t_lab	*new;

	new = (t_lab *)malloc(sizeof(t_lab *));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->name = cur->str;
	if (cur->next && cur->next == OP)
	{
		new->line = cur->next->row;
		new->pos = cur->next->col;
	}
	else if (cur->next && cur->next->next && cur->next->next == OP)
	{
		new->line = cur->next->next->row;
		new->pos = cur->next->next->col;
	}
	if (!cur && !prev)
		error_asm(d, NULL, -1);
}

void	token_to_statement(t_asm *d, t_oken *cur, t_oken *prev)
{
	t_stat	*new;

	if (!d->head.prog_name[0] || !d->head.comment[0])
		asm_token_error(d, cur, STX_ERR);
	new = (t_stat *)malloc(sizeof(t_stat));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	if (cur->type == OP)
		save_statement(d, cur, prev);
	else if (cur->type == LABEL)
		save_label(d, cur, prev);
	else
		save_argument(d, cur, prev);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/13 15:39:10 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	save_comment(t_asm *d, t_oken *cur)
{
	int	i;

	i = 1;
	if (d->head.comment[0])
		asm_token_error(d, cur, STX_ERR);
	else if (ft_strlen(cur->str) > COMMENT_LENGTH + 2)
		asm_token_error(d, cur, COMMLEN_ERR);
	if (!ft_strcmp(cur->str, "\"\""))
			d->head.comment[0] = 1;
	else
	{
		while (cur->str[i] && cur->str[i] != '"')
		{
			d->head.comment[i - 1] = cur->str[i];
			i++;
		}
		d->head.comment[i - 1] = '\0';
	}
}

static void	save_name(t_asm *d, t_oken *cur)
{
	int	i;

	i = 1;
	if (d->head.prog_name[0])
		asm_token_error(d, cur, STX_ERR);
	else if (ft_strlen(cur->str) > PROG_NAME_LENGTH + 2)
		asm_token_error(d, cur, NAMELEN_ERR);
	if (!ft_strcmp(cur->str, "\"\""))
		d->head.prog_name[0] = 1;
	else
	{
		while (cur->str[i] && cur->str[i] != '"')
		{
			d->head.prog_name[i - 1] = cur->str[i];
			i++;
		}
		d->head.prog_name[i - 1] = '\0';
	}
}

static void	save_header(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (prev && prev->type != NEWLINE && prev->type != NAME \
	&& prev->type != COMMENT)
		asm_token_error(d, cur, STX_ERR);
	if (cur->type == NAME)
		save_name(d, cur);
	else
		save_comment(d, cur);
}

static void	syntax_checker(t_asm *d)
{
	t_oken	*tmp;
	t_oken	*prev;

	tmp = d->tokens;
	prev = NULL;
	while (tmp)
	{
		if (tmp->type == NAME || tmp->type == COMMENT)
			save_header(d, tmp, prev);
		else if (tmp->type == DIR || tmp->type == IND || tmp->type == REG || \
		tmp->type == DIRLAB || tmp->type == INDIRLAB)
			save_argument(d, tmp, prev, d->tail_statement);
		else if (tmp->type != SEPARATOR && tmp->type != NEWLINE)
			token_to_statement(d, tmp, prev);
		prev = tmp;
		tmp = tmp->next;
		if (tmp != NULL && prev != NULL && tmp->type == NEWLINE && \
		prev->type == SEPARATOR)
			asm_token_error(d, tmp, ENDLINE_ERR);
	}
	if (prev->type != NEWLINE)
		exit_asm(d, NO_NL_END_STR);
	// if end reached and d->unref_labels == true
	//		point those unreferenced to the place after the champ code
	// THEN: check reference to labels. + count size.
}

/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for basic errors.
*/

/* static void	print_labels(t_lab **table)
{
	size_t	i;
	t_lab	*tmp;

	i = -1;
	while (table[++i])
	{
		tmp = table[i];
		while (tmp)
		{
			ft_printf("%s stat: %p\n", tmp->name, tmp->statement);
			tmp = tmp->next;
		}
	}
} */

void	lexer(t_asm *d)
{
	tokenize(d);
	init_label_table(d);
	syntax_checker(d);
	label_checker(d);
	//print_labels(d->labels);
	//ft_printf("Name: [%s]\nComm: [%s]\n", d->head.prog_name, d->head.comment);
	//parse(d);
}
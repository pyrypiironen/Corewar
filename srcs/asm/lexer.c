/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/03/13 19:45:13 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Saves the given comment of the champion in the t_header struct.
*/

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

/*
** Saves the given name of the champion in the t_header struct.
*/

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

/*
** Checks the syntax of the command tokens and the previous token. If these
** commands were already given, this is considered an error and the program
** exits.
*/

static void	save_header(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (prev && prev->type != NEWLINE && prev->type != NAME \
	&& prev->type != COMMENT)
		asm_token_error(d, cur, STX_ERR);
	if (cur->type == NAME && !d->head.prog_name[0])
		save_name(d, cur);
	else if (cur->type == COMMENT && !d->head.comment[0])
		save_comment(d, cur);
	else
		exit_asm(d, DOUBLE_CMD_ERR);
}

/*
** Iterates through all tokens, validates them and the order they come in.
** If an error is found, an error function is called to print an error message,
** free up allocated memory and exit the program.
*/

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
		if (tmp->type == NEWLINE && d->tail_statement && \
		!d->tail_statement->valid)
			asm_token_error(d, tmp, ENDLINE_ERR);
		prev = tmp;
		tmp = tmp->next;
		if (valid_token_order(tmp, prev) == false)
			asm_token_error(d, tmp, STX_ERR);
	}
	if (prev->type != NEWLINE)
		exit_asm(d, NO_NL_END_STR);
}

/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for basic errors.
*/

void	lexer(t_asm *d)
{
	tokenize(d);
	init_label_table(d);
	syntax_checker(d);
	if (d->tail_statement && d->tail_statement->valid == false)
		asm_token_error(d, NULL, ARGCOUNT_ERR);
	if (!d->n_labels && !d->statements)
		error_asm(d, NULL, EOF_ERR);
	if (d->n_labels != 0 && d->statements != NULL)
		label_checker(d);
	if (d->statements != NULL)
		translate_calculations(d);
}

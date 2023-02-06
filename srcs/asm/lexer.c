/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/06 18:15:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/* static void	save_argument(t_asm *d, t_oken *cur, t_oken *prev)
{

}

static void	save_statement(t_asm *d, t_oken *cur, t_oken *prev)
{

}

static void	save_label(t_asm *d, t_oken *cur, t_oken *prev)
{

} */

static void	save_comment(t_asm *d, t_oken *cur)
{
	int	i;

	i = 1;
	if (d->head.comment[0])
		asm_token_error(d, cur);
	else if (ft_strlen(cur->str) > COMMENT_LENGTH + 2)
		asm_token_error(d, cur);
	//double check the length
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
		asm_token_error(d, cur);
	else if (ft_strlen(cur->str) > PROG_NAME_LENGTH + 2)
		asm_token_error(d, cur);
	//double check the length
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
	// validate NEWLINES, remove them.
	if (prev && prev->type != NEWLINE && prev->type != NAME \
	&& prev->type != COMMENT)
		asm_token_error(d, cur);
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
	// check one token at a time, add to linked list of statements, hash table of labels..
	while (tmp)
	{
		if (tmp->type == NAME || tmp->type == COMMENT)
			save_header(d, tmp, prev);
		/* else if (tmp->type == OP)
			save_statement(d, tmp, prev);
		else if (tmp->type == LABEL)
			save_label(d, tmp, prev);
		else if (tmp->type == DIR || tmp->type == IND || tmp->type == REG || \
		tmp->type == DIRLAB)
			save_argument(d, tmp, prev); */
		// validate separator && newline
		prev = tmp;
		tmp = tmp->next;
	}
}

/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for basic errors.
*/

void	lexer(t_asm *d)
{
	tokenize(d);
	syntax_checker(d);
	ft_printf("Name: [%s]\nComm: [%s]\n", d->head.prog_name, d->head.comment);
	//parse(d);
}
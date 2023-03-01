/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/28 14:13:51 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Checks the type of the token, and saves it if valid and exits if not.
*/

static int	check_type(t_asm *d, char *str)
{
	int		len;
	t_type	type;

	len = 0;
	type = VOID;
	if (str[len] == '\n')
	{
		add_token(d, str, 1, NEWLINE);
		return (1);
	}
	else if (str[len] == SEPARATOR_CHAR)
		return (add_token(d, str, 1, SEPARATOR));
	else if (is_label(str, &len))
	{
		return (add_token(d, str, len, LABEL));
	}
	else if (is_op(str, &len))
		return (add_token(d, str, len, OP));
	else if (is_arg(d, str, &len, &type))
		return (add_token(d, str, len, type));
	else if (is_command(d, str, &len, &type))
		return (len);
	else
		return (set_error_pos(d, d->i, LEX_ERR));
}

/*
** Skips the buffer until the next line is reached.
*/

static int	skip_to_next_line(t_asm *d, char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
	{
		d->col++;
		len++;
	}
	if (!str[len])
		return (EOF_ERR);
	add_token(d, &str[len], 1, NEWLINE);
	len++;
	return (len);
}

/*
** Helper function for add_token().
*/

static void	add_token_helper(t_asm *d, t_oken *new, t_type type)
{
	if (type == NEWLINE)
	{
		d->row++;
		d->col = 1;
	}
	else if (type == LABEL)
		d->n_labels++;
	new->next = NULL;
	new->type = type;
	new->row = d->row;
	new->col = d->col;
}

/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for lexical errors.
*/

int	add_token(t_asm *d, char *str, int len, t_type type)
{
	t_oken	*new;
	t_oken	*tmp;

	tmp = d->tokens;
	new = (t_oken *)malloc(sizeof(t_oken));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	add_token_helper(d, new, type);
	new->str = ft_strnew((size_t)len);
	if (!new->str)
		memdel_exit_asm(d, new, MALLOC_ERR);
	if (!new->str)
		error_asm(d, NULL, MAL_ERR);
	ft_strncpy(new->str, str, len);
	if (d->tokens == NULL)
	{
		d->tokens = new;
		return (len);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (len);
}

/*
** Iterates through the whole input or until an error is found. Cleans up the
** input from comments and whitespace, creates a linked list of tokens.
*/

void	tokenize(t_asm *d)
{
	int	ret;

	while (d->buf[d->i])
	{
		ret = 0;
		while (d->buf[d->i] && ft_strchr(" \t\r\v", (int)d->buf[d->i]))
		{
			d->i++;
			d->col++;
		}
		if (!d->buf[d->i])
			return ;
		if (d->buf[d->i] == COMMENT_CHAR || d->buf[d->i] == ALT_COMMENT_CHAR)
			ret = skip_to_next_line(d, &d->buf[d->i]);
		else
			ret = check_type(d, &d->buf[d->i]);
		if (ret == EOF_ERR)
			return ;
		d->i += ret;
		if (d->i && d->buf[d->i - 1] != '\n')
			d->col += ret;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/15 17:26:58 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	label_error(t_oken *cur)
{
	size_t	start;
	char	*label;

	start = 1;
	label = NULL;
	if (cur)
		label = cur->str;
	else
	{
		ft_printf("No such label\n");
		return ;
	}
	if (label[start] == ':')
	{
		start++;
		ft_printf("No such label %s while attempting to dereference token \
[TOKEN][%03d:%03d] DIRECT_LABEL \"%s\"\n", &label[start], cur->row, cur->col, \
label);
	}
	else
		ft_printf("No such label %s while attempting to dereference token \
[TOKEN][%03d:%03d] INDIRECT_LABEL \"%s\"\n", &label[start], cur->row, \
cur->col, label);
}

static void	asm_syntax_error(t_oken *cur, int status)
{
	if (status == EOF_ERR)
		ft_printf("Syntax error at [%d:%d] EOF\n", cur->row, cur->col);
	else if (cur)
	{
		if (cur->type == OP)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \
\"%s\"\n", cur->row, cur->col, cur->str);
		else if (cur->type == REG)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] REGISTER \
\"%s\"\n", cur->row, cur->col, cur->str);
		else if (cur->type == LABEL)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] INDIRECT_LABEL \
\"%s\"\n", cur->row, cur->col, cur->str);
		else if (cur->type == DIR)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] DIRECT \
\"%s\"\n", cur->row, cur->col, cur->str);
		else if (cur->type == IND)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] INDIRECT \
\"%s\"\n", cur->row, cur->col, cur->str);
		else if (cur->type == DIRLAB)
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] DIRECT_LABEL \
\"%s\"\n", cur->row, cur->col, cur->str);
	}
	else
		ft_printf("Syntax error at token [%03d:%03d]\n", cur->row, cur->col);
}

void	asm_token_error(t_asm *d, t_oken *cur, int status)
{
	if (status == NAMELEN_ERR)
		ft_putstr_fd(NAME_ERR, STDERR_FILENO);
	else if (status == COMMLEN_ERR)
		ft_putstr_fd(COMMENT_ERR, STDERR_FILENO);
	else if (status == ARGCOUNT_ERR)
		ft_putstr_fd(ARGCOUNT_ERR_STR, STDERR_FILENO);
	else if (status == ENDLINE_ERR)
		ft_printf("Syntax error at token [%03d:%03d] ENDLINE\n", \
		cur->row, cur->col);
	else if (status == NOLABEL_ERR)
		label_error(cur);
	else
		asm_syntax_error(cur, status);
	free_asm(d);
	exit(EXIT_FAILURE);
}

void	error_asm(t_asm *d, char *line, int status)
{
	if (status == LEX_ERR)
		ft_printf("Lexical error at [%d:%d]\n", d->row, d->col);
	else if (status == STX_ERR || status == EOF_ERR)
		asm_syntax_error(NULL, status);
	else if (status == MAL_ERR)
		ft_putstr_fd(MALLOC_ERR, STDERR_FILENO);
	if (line)
		ft_strdel(&line);
	free_asm(d);
	exit(EXIT_FAILURE);
}

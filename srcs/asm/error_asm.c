/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:31 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	asm_syntax_error(t_asm *d, t_oken *cur, int status)
{
	if (status == EOF_ERR)
		ft_printf("Syntax error at [%d:%d] EOF\n", d->row, d->col);
	else if (cur)
	{
		if (cur->type == OP)
			ft_printf("Syntax error at token [%d:%d] INSTRUCTION \"%s\"\n", \
			d->row, d->col, cur->str);
		else if (cur->type == REG)
			ft_printf("Syntax error at token [%d:%d] REGISTER \"%s\"\n", \
			d->row, d->col, cur->str);
		else if (cur->type == LABEL)
			ft_printf("Syntax error at token [%d:%d] INDIRECT_LABEL \"%s\"\n", \
			d->row, d->col, cur->str);
		else if (cur->type == DIR)
			ft_printf("Syntax error at token [%d:%d] DIRECT \"%s\"\n", \
			d->row, d->col, cur->str);
		else if (cur->type == IND)
			ft_printf("Syntax error at token [%d:%d] INDIRECT \"%s\"\n", \
			d->row, d->col, cur->str);
		else if (cur->type == DIRLAB)
			ft_printf("Syntax error at token [%d:%d] DIRECT_LABEL \"%s\"\n", \
			d->row, d->col, cur->str);
	}
	else
		ft_printf("Syntax error at token [%d:%d]\n", d->row, d->col);
}

void	asm_token_error(t_asm *d, t_oken *cur, int status)
{
	if (status == NAMELEN_ERR)
		ft_putstr_fd(NAME_ERR, STDERR_FILENO);
	else if (status == COMMLEN_ERR)
		ft_putstr_fd(COMMENT_ERR, STDERR_FILENO);
	else
		asm_syntax_error(d, cur, status);
	free_asm(d);
	exit(EXIT_FAILURE);
}

void	error_asm(t_asm *d, char *line, int status)
{
	//ft_printf("[%c]\n", d->buf[d->i]);
	if (status == LEX_ERR)
		ft_printf("Lexical error at [%d:%d]\n", d->row, d->col);
	else if (status == STX_ERR || status == EOF_ERR)
		asm_syntax_error(d, NULL, status);
	if (line)
		ft_strdel(&line);
	free_asm(d);
	exit(EXIT_FAILURE);
}
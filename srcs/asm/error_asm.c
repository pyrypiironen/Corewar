/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/06 17:24:19 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	asm_syntax_error(t_asm *d, int status)
{
	if (status == EOF_ERR)
		ft_printf("Syntax error at [%d:%d] EOF\n", d->row, d->col);
	else
		ft_printf("Syntax error at token [%d:%d]\n", d->row, d->col);
}

void	asm_token_error(t_asm *d, t_oken *cur)
{
	ft_printf("Syntax error at token [%d:%d]\n", cur->row, cur->col);
	free_asm(d);
	exit(EXIT_FAILURE);
}

void	error_asm(t_asm *d, char *line, int status)
{
	//ft_printf("[%c]\n", d->buf[d->i]);
	if (status == LEX_ERR)
		ft_printf("Lexical error at [%d:%d]\n", d->row, d->col);
	else if (status == STX_ERR || status == EOF_ERR)
		asm_syntax_error(d, status);
	if (line)
		ft_strdel(&line);
	free_asm(d);
	exit(EXIT_FAILURE);
}
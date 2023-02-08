/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:07:05 by abackman          #+#    #+#             */
/*   Updated: 2023/02/08 17:10:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/* static void	validate_arg(t_asm *d, t_oken *cur, char *argstr, t_stat *dst)
{
	
} */

static uint8_t	validate_type(t_asm *d, t_oken *cur, t_stat *dst)
{
	if (cur->type == REG)
	{
		if (g_op_tab[dst->opcode].arg_type[dst->cur_arg] != T_REG)
			memdel_exit_asm(d, dst, "Invalid argument type\n");
		else
			return (T_REG);
	}
	if (cur->type == DIR || cur->type == DIRLAB)
	{
		if (g_op_tab[dst->opcode].arg_type[dst->cur_arg] != T_DIR)
			memdel_exit_asm(d, dst, "Invalid argument type\n");
		else
			return (T_DIR);
	}
	if (cur->type == IND || cur->type == INDIRLAB)
	{
		if (g_op_tab[dst->opcode].arg_type[dst->cur_arg] != T_IND)
			memdel_exit_asm(d, dst, "Invalid argument type\n");
		else
			return (T_IND);
	}
}

static void	add_arg_to_statement(t_asm *d, t_oken *cur, t_stat *dst)
{
	uint8_t	type;

	type = 0;
	if (dst->cur_arg + 1 > g_op_tab[dst->opcode].expected_arg_count)
		asm_token_error(d, cur, ARGCOUNT_ERR);
	// check that the type and value are correct
	type = validate_type(d, cur, dst);
	dst->argtypes[dst->cur_arg] = type;
	// check value, add to args[], or label?
}

void	save_argument(t_asm *d, t_oken *cur, t_oken *prev)
{
	ft_printf("Save argument__\n");
	if (!cur && !prev)
		error_asm(d, NULL, -1);
	if (!d->head.prog_name[0] || !d->head.comment[0] || !d->tail_statement)
		asm_token_error(d, cur, STX_ERR);
	if (d->tail_statement->valid)
		asm_token_error(d, cur, STX_ERR);
	add_arg_to_statement(d, cur, d->tail_statement);
	// if all args are met, valid = true
	// if tail_statement == valid && d->unref_labels
}

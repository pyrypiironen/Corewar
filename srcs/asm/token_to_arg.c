/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:07:05 by abackman          #+#    #+#             */
/*   Updated: 2023/02/28 14:18:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static uint8_t	validate_type(t_asm *d, t_oken *cur, t_stat *dst)
{
	if (cur->type == REG)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_REG))
			exit_asm(d, "Invalid REGISTRY argument type\n");
		else
			return (T_REG);
	}
	if (cur->type == DIR || cur->type == DIRLAB)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_DIR))
			exit_asm(d, "Invalid DIRECT argument type\n");
		else
			return (T_DIR);
	}
	if (cur->type == IND || cur->type == INDIRLAB)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_IND))
			exit_asm(d, "Invalid INDIRECT argument type\n");
		else
			return (T_IND);
	}
	return (0);
}

static void	arg_registry(t_asm *d, t_oken *cur, t_stat *dst)
{
	int		res;
	size_t	len;

	len = ft_strlen(cur->str);
	if (len > 3 || len < 2 || cur->str[0] != 'r')
		asm_token_error(d, cur, STX_ERR);
	if (!ft_isdigit((int)cur->str[1]) && (cur->str[2] && \
	!ft_isdigit((int)cur->str[2])))
		asm_token_error(d, cur, STX_ERR);
	res = ft_atoi(&cur->str[1]);
	dst->args[dst->cur_arg] = res;
}

static void	arg_label(t_asm *d, t_oken *cur, t_stat *dst)
{
	size_t	start;

	start = 1;
	if (cur->type == DIRLAB)
		start = 2;
	if (cur->type == INDIRLAB)
		dst->argtypes[dst->cur_arg] = IND;
	else
		dst->argtypes[dst->cur_arg] = DIR;
	dst->arglabel[dst->cur_arg] = &cur->str[start];
	if (!dst->arglabel[dst->cur_arg])
		error_asm(d, NULL, MAL_ERR);
}

static void	arg_integer(t_asm *d, t_oken *cur, t_stat *dst)
{
	size_t	start;

	start = 0;
	if (cur->type == DIR)
		start = 1;
	if (cur->type == IND)
		dst->argtypes[dst->cur_arg] = IND;
	else
		dst->argtypes[dst->cur_arg] = DIR;
	dst->args[dst->cur_arg] = ft_atoi(&cur->str[start]);
	if (cur->str[start] == '-')
		start++;
	while (cur->str[start])
	{
		if (!ft_isdigit((int)cur->str[start++]))
			asm_token_error(d, cur, STX_ERR);
	}
}

void	save_argument(t_asm *d, t_oken *cur, t_oken *prev, t_stat *dst)
{
	uint8_t	type;

	if (!cur && !prev)
		error_asm(d, NULL, -1);
	if (!d->head.prog_name[0] || !d->head.comment[0] || !dst)
		asm_token_error(d, cur, STX_ERR);
	if (dst->cur_arg + 1 > g_op_tab[dst->opcode].expected_arg_count)
		asm_token_error(d, cur, STX_ERR);
	type = validate_type(d, cur, dst);
	dst->argtypes[dst->cur_arg] = type;
	if (cur->type == REG)
		arg_registry(d, cur, dst);
	else if (cur->type == DIRLAB || cur->type == INDIRLAB)
		arg_label(d, cur, dst);
	else
		arg_integer(d, cur, dst);
	dst->cur_arg++;
	if (dst->cur_arg == g_op_tab[dst->opcode].expected_arg_count)
		dst->valid = true;
	if (dst->valid && d->unref_labels)
		add_statement_to_labels(d, dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:07:05 by abackman          #+#    #+#             */
/*   Updated: 2023/02/10 15:09:44 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/* static void	validate_arg(t_asm *d, t_oken *cur, char *argstr, t_stat *dst)
{
	
} */

static uint8_t	validate_type(t_asm *d, t_oken *cur, t_stat *dst)
{
	//ft_printf("\nARG--> [%s]\nTYPE-> %u\nOP---> %u\n", cur->str, cur->type, dst->opcode);
	if (cur->type == REG)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_REG))
			memdel_exit_asm(d, dst, "Invalid REG argument type\n");
		else
			return (T_REG);
	}
	if (cur->type == DIR || cur->type == DIRLAB)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_DIR))
			memdel_exit_asm(d, dst, "Invalid DIR argument type\n");
		else
			return (T_DIR);
	}
	if (cur->type == IND || cur->type == INDIRLAB)
	{
		if (!(g_op_tab[dst->opcode].arg_type[dst->cur_arg] & T_IND))
			memdel_exit_asm(d, dst, "Invalid IND argument type\n");
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
	//ft_printf("ADDED %s as ARG # %u to %u\n", cur->str, dst->cur_arg, dst);
	res = ft_atoi(&cur->str[1]);
	dst->args[dst->cur_arg] = res;
}

//arg_lab()

//arg_num()

void	save_argument(t_asm *d, t_oken *cur, t_oken *prev, t_stat *dst)
{
	uint8_t	type;

	//ft_printf("\n\t*save_argument*\n %p\nvalid: %u\n", dst, dst->valid);
	if (!cur && !prev)
		error_asm(d, NULL, -1);
	if (!d->head.prog_name[0] || !d->head.comment[0] || !dst)
		asm_token_error(d, cur, STX_ERR);
	if (dst->cur_arg + 1 > g_op_tab[dst->opcode].expected_arg_count)
		asm_token_error(d, cur, ARGCOUNT_ERR);
	type = validate_type(d, cur, dst);
	dst->argtypes[dst->cur_arg] = type;
	if (cur->type == REG)
		arg_registry(d, cur, dst);
	/* else if (cur->type == DIRLAB || cur->type == INDIRLAB)
		arg_label(d, cur, dst);
	else
		arg_integer(d, cur, dst); */
	dst->cur_arg++;
	if (dst->cur_arg == g_op_tab[dst->opcode].expected_arg_count)
		dst->valid = true;
	if (dst->valid && d->unref_labels)
		add_statement_to_labels(d, dst);
}

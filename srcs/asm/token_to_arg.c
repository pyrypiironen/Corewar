/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:07:05 by abackman          #+#    #+#             */
/*   Updated: 2023/02/08 12:21:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	save_argument(t_asm *d, t_oken *cur, t_oken *prev)
{
	if (!cur && !prev)
		error_asm(d, NULL, -1);
	if (!d->head.prog_name[0] || !d->head.comment[0])
		asm_token_error(d, cur, STX_ERR);
	if (d->tail_statement->valid)
		asm_token_error(d, cur, STX_ERR);
	// if all args are met, valid = true
	// if tail_statement == valid && d->unref_labels
}

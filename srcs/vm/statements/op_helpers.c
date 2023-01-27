/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:35 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 12:47:36 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "../../../includes/vm.h"

// int	is_valid_statement(t_carriage *carriage, t_vm_data *d)
// {
// 	unsigned char first = ((carriage->cursor + 1) & 0xc0) >> 6;
// 	unsigned char second = ((carriage->cursor + 1)& 0x30) >> 4;
// 	unsigned char third = ((carriage->cursor + 1) & 0x0c) >> 2;
// }

int	is_valid_reg(int position, t_vm_data *d)
{
	int	ret;

	ret = 0;
	if (d->arena[position] > 0 && d->arena[position] <= REG_NUMBER)
		ret = 1;
	return (ret);
}

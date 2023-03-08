/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:19:10 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/27 13:19:11 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

// The fork statement makes a copy of the carriage. And this copy is placed at
// the address <first arg> % IDX_MOD.
void	op_fork(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	first;
	unsigned char	second;
	short			arg;
	t_carriage		*new;

	first = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	second = d->arena[(carriage->cursor + 2) % MEM_SIZE];
	arg = ((first << 8) + second);
	new = (t_carriage *)malloc(sizeof(t_carriage));
	if (new == NULL)
		print_error("Malloc failed.", 0);
	new->next = d->carriage_head;
	d->carriage_head = new;
	copy_carriage(carriage, d);
	if (d->a_flag != -2)
		ft_printf("P%5d | fork %d (%d)\n", carriage->id, arg, \
		(carriage->cursor + arg) % IDX_MOD);
	d->carriage_head->cursor = (carriage->cursor + (arg % IDX_MOD)) % MEM_SIZE;
	carriage->cursor = (carriage->cursor + 3) % MEM_SIZE; // Modified 4 to 3
}

// Long lfork statement. Same than fork statement, but can place new carriage
// further than 512 memory location away.
void	op_lfork(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	first;
	unsigned char	second;
	short			arg;
	t_carriage		*new;

	first = d->arena[(carriage->cursor + 1) % MEM_SIZE];
	second = d->arena[(carriage->cursor + 2) % MEM_SIZE];
	arg = ((first << 8) + second);
	new = (t_carriage *)malloc(sizeof(t_carriage));
	if (new == NULL)
		print_error("Malloc failed.", 0);
	new->next = d->carriage_head;
	d->carriage_head = new;
	copy_carriage(carriage, d);
	if (d->a_flag != -2)
		ft_printf("P%5d | lfork %d (%d)\n", carriage->id, arg, \
		carriage->cursor + arg);
	d->carriage_head->cursor = (carriage->cursor + arg) % MEM_SIZE;
	carriage->cursor = (carriage->cursor + 4) % MEM_SIZE;
}

void	copy_carriage(t_carriage *carriage, t_vm_data *d)
{
	int	i;

	i = 0;
	d->carriage_head->id = carriage->id;
	d->carriage_head->carry = carriage->carry;
	d->carriage_head->last_live = carriage->last_live;
	d->carriage_head->statement = 0;
	d->carriage_head->to_execute = -1;
	d->carriage_head->jump_size = 0;
	while (i < REG_NUMBER)
	{
		d->carriage_head->registrys[i] = carriage->registrys[i];
		i++;
	}
}

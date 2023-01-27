/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:20:25 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/12 16:20:27 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

int	main(int argc, char **argv)
{
	t_vm_data	*d;
	
	d = (t_vm_data *)malloc(sizeof(t_vm_data));
	if (d == NULL)
		print_error("Malloc failed.", 0);
	if (argc < 2)
		print_error("Wrong usage. Invalid amount of arguments.", 1);
	init_core(argc, argv, d);





	

	d->arena[4094] = 0x0d;
	d->arena[4095] = 0x10;
	d->arena[0] = 0x40;
	d->carriage_head->registrys[2] = 322;
	d->arena[1] = 0x03;
	d->arena[2] = 0x10;
	d->carriage_head->cursor = 4095;
	d->carriage_head->carry = 1;


	

	print_carriages(d);
	op_aff(d->carriage_head, d);
	//op_jump(d->carriage_head, d);
	//print_arena(d);
	//op_add(d->carriage_head, d);

	ft_printf("{red} *	*	*	*	*	*	*	*	*	*	\n");
	//print_arena(d);
	print_carriages(d);

	ft_printf("{green}Success! Main exit (exit code 0).\n");
	exit (0);
}
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





	

	d->arena[4084] = 0xd0; // argument value code
	d->arena[4085] = 0x01;
	d->arena[4086] = 0xC8;

	d->arena[4087] = 5;

	d->arena[187] = 0x7f; // + 200
	d->arena[188] = 0xff;
	d->arena[189] = 0xff;
	d->arena[190] = 0xff;


	d->carriage_head->cursor = 4083; // 187
	d->carriage_head->carry = 1;

	d->carriage_head->registrys[2] = 322;


	

	print_carriages(d);
	op_ld(d->carriage_head, d);
	//op_jump(d->carriage_head, d);
	//print_arena(d);
	//op_add(d->carriage_head, d);

	ft_printf("{red} *	*	*	*	*	*	*	*	*	*	\n");
	//print_arena(d);
	print_carriages(d);

	ft_printf("{green}Success! Main exit (exit code 0).\n");
	exit (0);
}
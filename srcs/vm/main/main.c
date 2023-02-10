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


	d->arena[4084] = 0x78;		// argument value code
	d->arena[4085] = 0x01;		// 
	d->arena[4086] = 0x00;		// 
	d->arena[4087] = 0x07;		// 
	d->arena[4088] = 0x00;		// 
	d->arena[4089] = 0x64; 		// 
	d->arena[4090] = 0x00;		// 
	
	d->arena[4091] = 0x00; 		// reg
	d->arena[4092] = 0x02;		// 
	d->arena[4093] = 0x64; 		//  reg
	d->arena[4094] = 0x32;		//


	d->arena[187] = 0x7f;
	d->arena[188] = 0x0f;
	d->arena[189] = 0xff;
	d->arena[190] = 0xff;
	d->arena[287] = 0x00;
	d->arena[288] = 0x00;
	d->arena[289] = 0x00;
	d->arena[290] = 0x00;
	// d->arena[187 + 512] = 0x7f;
	// d->arena[188 + 512] = 0xff;
	// d->arena[189 + 512] = 0xff;
	// d->arena[190 + 512] = 0xff;



	d->carriage_head->cursor = 4083;
	d->carriage_head->carry = 0;

	d->carriage_head->registrys[0] = 50;
	d->carriage_head->registrys[1] = 100;
	d->carriage_head->registrys[2] = 2100000;
	d->carriage_head->registrys[3] = 612;


	
	print_arena(d);
	print_carriages(d);
	op_sti(d->carriage_head, d);
	//op_jump(d->carriage_head, d);
	//op_add(d->carriage_head, d);
	//op_lldi(d->carriage_head, d);


	ft_printf("{red} *	*	*	*	*	*	*	*	*	*	\n");
	//print_arena(d);
	print_carriages(d);
	print_arena(d);

	ft_printf("{green}Success! Main exit (exit code 0).\n");
	exit (0);
}
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





	
	// reg - ind - reg

	d->arena[4084] = 0xf4;		// argument value code
	d->arena[4085] = 0x02;		// start of first
	d->arena[4086] = 0xc8; 		// end of first
	d->arena[4087] = 0x03;		// start of second
	d->arena[4088] = 0x2c;		// end of second
	d->arena[4089] = 0x0a; 		// reg
	d->arena[4090] = 0xc8;		// end of second
	
	d->arena[4091] = 0x0a; 		// reg

	d->arena[4092] = 0x2c;		// 
	d->arena[4093] = 0x0a; 		//  reg
	d->arena[4094] = 0x0a;		//


	d->arena[187] = 0x7f;
	d->arena[188] = 0xff;
	d->arena[189] = 0xff;
	d->arena[190] = 0xff;
	d->arena[287] = 0x00;
	d->arena[288] = 0x00;
	d->arena[289] = 0x00;
	d->arena[290] = 0x00;


	d->carriage_head->cursor = 4083;
	d->carriage_head->carry = 0;

	d->carriage_head->registrys[2] = 2100000;
	d->carriage_head->registrys[3] = 44;


	

	print_carriages(d);
	//op_st(d->carriage_head, d);
	//op_jump(d->carriage_head, d);
	//op_add(d->carriage_head, d);
	op_and(d->carriage_head, d);


	ft_printf("{red} *	*	*	*	*	*	*	*	*	*	\n");
	//print_arena(d);
	print_carriages(d);
	//print_arena(d);

	ft_printf("{green}Success! Main exit (exit code 0).\n");
	exit (0);
}
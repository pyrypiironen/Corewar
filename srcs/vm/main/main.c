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
	print_contestants(d);
	play_the_game(d);
	




	// * * * * * * * * * * ONLY TESTING * * * * * * * * * *
	// int res;
	// unsigned char x = 168;
	// res = count_jump_size(x, 2, 1);
	// ft_printf("res = %i\n", res);

	// 11 11 11 00 = 252 --> 6
	// 10 10 10 00 = 168 --> 6 or 12
	// 01 01 01 00 = 84 --> 3
	// 00 00 00 00 = 0 --> 0




	// d->arena[4084] = 0xff;		// argument value code
	// d->arena[4085] = 0xff;		// 
	// d->arena[4086] = 0xff;		// 
	// d->arena[4087] = 0xfe;		// 
	// d->arena[4088] = 0x00;		// 
	// d->arena[4089] = 0x64; 		// 
	// d->arena[4090] = 0x00;		// 
	
	// d->arena[4091] = 0x00; 		// reg
	// d->arena[4092] = 0x02;		// 
	// d->arena[4094] = 0x00; 		// reg
	// d->arena[4095] = 0x00;		//
	// d->arena[0] = 0x00; 		// reg
	// d->arena[1] = 0x02;


	// d->arena[187] = 0x7f;
	// d->arena[188] = 0x0f;
	// d->arena[189] = 0xff;
	// d->arena[190] = 0xff;
	// d->arena[287] = 0x00;
	// d->arena[288] = 0x00;
	// d->arena[289] = 0x00;
	// d->arena[290] = 0x00;
	// // d->arena[187 + 512] = 0x7f;
	// // d->arena[188 + 512] = 0xff;
	// // d->arena[189 + 512] = 0xff;
	// // d->arena[190 + 512] = 0xff;



	// d->carriage_head->cursor = 4093;
	// d->carriage_head->carry = 0;

	// d->carriage_head->registrys[0] = 50;
	// d->carriage_head->registrys[1] = 100;
	// d->carriage_head->registrys[2] = 2100000;
	// d->carriage_head->registrys[3] = 612;
	// d->current_cycle = 42;


	
	// //print_arena(d);
	// print_carriages(d);
	// op_live(d->carriage_head, d);
	// //op_sti(d->carriage_head, d);
	// //op_jump(d->carriage_head, d);
	// //op_add(d->carriage_head, d);
	// //op_lldi(d->carriage_head, d);


	// ft_printf("{red} *	*	*	*	*	*	*	*	*	*	\n");
	// //print_arena(d);
	// print_carriages(d);
	// ft_printf("{red}winner: %d\n", d->winner);
	// //print_arena(d);


	ft_printf("{green}Success! Main exit (exit code 0).{eoc}\n");
	exit (0);
}
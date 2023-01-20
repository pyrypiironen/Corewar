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




	
	// print_champs(d);
	// print_carriages(d);
	// print_arena(d);

	ft_printf("{green}Success! Main exit (exit code 0).\n");
	exit (0);
}
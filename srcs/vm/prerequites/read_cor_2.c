/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:16:05 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/19 17:16:07 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm.h"

void	read_excode(t_player *champ, int fd)
{
	//unsigned char	buf[champ->code_size];

	champ->excode = (unsigned char *)malloc(sizeof(unsigned char) * \
	champ->code_size);
	if (champ->excode == NULL)
		print_error("Malloc failed.", 0);
	if (read(fd, champ->excode, champ->code_size + 1) != champ->code_size)
		print_error("Invalid file.", 0);

	// Test
	int i = 0;
	ft_printf("{blue}Excode: ");
	while (i < champ->code_size)
	{
		ft_printf("{yellow}%.2X", champ->excode[i]);
		i++;
		if (i == champ->code_size)
		 break ;
		ft_printf("{yellow}%.2X ", champ->excode[i]);
		i++;
	}
	ft_printf("\n");
}

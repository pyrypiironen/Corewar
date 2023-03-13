/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:16:05 by ppiirone          #+#    #+#             */
/*   Updated: 2023/03/13 14:08:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// Read execution code of champion from .cor file and check the validity.
void	read_excode(t_player *champ, int fd)
{
	champ->excode = (unsigned char *)malloc(sizeof(unsigned char) * \
	champ->code_size);
	if (champ->excode == NULL)
		print_error("Malloc failed.", 0);
	if (read(fd, champ->excode, champ->code_size + 1) != champ->code_size)
		print_error("Invalid file. Champions executable code doens't match \
code size.", 0);
	if (champ->code_size > CHAMP_MAX_SIZE)
		print_error("Invalid file. Champions executable code is too long.", 0);
}

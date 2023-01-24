/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:41 by abackman          #+#    #+#             */
/*   Updated: 2023/01/24 16:25:56 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** 1. get labels into label hashtable: each time a label is found, go forward 
** until you found the line/statement it points to, then go back.
** 2. get statements, save in linked list. Save only name of label.
*/

void	parse_file(t_asm *d)
{
	
	get_header(d);
	// get_statements(d)
	// get_
	/* while (get_next_line(d->fd, &line))
	{
		ft_strdel(&line);
	} */
}
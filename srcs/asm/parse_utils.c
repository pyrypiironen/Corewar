/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:53:40 by abackman          #+#    #+#             */
/*   Updated: 2023/01/30 13:57:35 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	set_error_pos(t_asm *d, int	pos, int status)
{
	int	x;
	int	y;
	int	i;

	x = 1;
	y = 1;
	i = 0;
	while (i < pos)
	{
		if (d->buf[i] == '\n')
		{
			y++;
			x = 0;
		}
		i++;
		x++;
	}
	d->row = y;
	d->col = x;
	if (status < 0)
		error_asm(d, NULL, status);
	return (status);
}

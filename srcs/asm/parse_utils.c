/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:53:40 by abackman          #+#    #+#             */
/*   Updated: 2023/01/24 18:22:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	clean_end(t_asm *d, char *line)
{
	while (line[d->col])
	{
		if (line[d->col] == '#' || line[d->col] == ';')
			return ;
		if (!ft_iswhitespace((int)line[d->col]))
			memdel_exit_asm(d, line, LEX_ERR);
		d->col++;
	}
}

int	save_next_line(t_asm *d)
{
	int	ret;
	
	ret = 0;
	ret = get_next_line(d->fd, &d->linebuf[d->row++]);
	return (ret);
}

void	set_error_pos(t_asm *d, int	pos)
{
	int	x;
	int	y;
	int	i;

	// TEST
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
}

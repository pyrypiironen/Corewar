/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:41 by abackman          #+#    #+#             */
/*   Updated: 2023/01/13 17:43:00 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	get_prog_name(t_asm *d)
{
	char	*line;

	line = NULL;
	get_next_line(d->fd, &line);
	//save all lines, make hashmap
	ft_strdel(&line);
}

static void	get_comment(t_asm *d)
{
	char	*line;

	line = NULL;
	get_next_line(d->fd, &line);
	ft_strdel(&line);
}

void	read_file(t_asm *d)
{
	char	*line;

	line = NULL;
	get_prog_name(d);
	get_comment(d);
	while (get_next_line(d->fd, &line))
	{
		ft_strdel(&line);
	}
}
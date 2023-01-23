/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:41 by abackman          #+#    #+#             */
/*   Updated: 2023/01/23 19:10:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	get_comment(t_asm *d, char *line)
{
	size_t	i;

	i = 0;
	if (d->head.comment[0])
		memdel_exit_asm(d, (void *)line, "ERROR: comment already given.\n");
}

// start memorizing where the errors occur, replicate original.

static void	get_name(t_asm *d, char *line)
{
	size_t	i;

	i = 0;
	if (d->head.prog_name[0])
		memdel_exit_asm(d, (void *)line, "ERROR: name already given.\n");
}

static void	get_header(t_asm *d)
{
	char	*line;
	uint8_t	saved;

	line = NULL;
	saved = 0;
	while (get_next_line(d->fd, &line))
	{
		if (!ft_strncmp(line, ".name", 5))
			get_name(d, line);
		else if (!ft_strncmp(line, ".comment", 8))
			get_comment(d, line);
		ft_strdel(&line);
		if (d->head.prog_name[0] && d->head.comment[0])
			return ;
	}
}

/*
** 1. get labels into label hashtable: each time a label is found, go forward 
** until you found the line/statement it points to, then go back.
** 2. get statements, save in linked list
*/

void	read_file(t_asm *d)
{
	char	*line;

	line = NULL;
	get_header(d);
	// get_statements(d)
	// get_
	/* while (get_next_line(d->fd, &line))
	{
		ft_strdel(&line);
	} */
}
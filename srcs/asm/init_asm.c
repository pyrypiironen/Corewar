/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:20:07 by abackman          #+#    #+#             */
/*   Updated: 2023/01/20 13:12:48 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// count lines, malloc double pointer char arr, read into it.
// count labels
// simultaneously check validity?
// in t_asm: keep a track of which line we are at
// functions: islabel(char *str) isstatement(char *str)

static void	count_lines_labels(t_asm *d)
{
	off_t	start;
	off_t	end;
	char	tmp[20];

	start = 0;
	end = 0;
	start = lseek(d->fd, 0, SEEK_SET);
	end = lseek(d->fd, start, SEEK_END);
	lseek(d->fd, start, SEEK_SET);
	if (start == -1 || end == -1 || start == end)
		exit_asm(d, "ERROR: invalid file");
	ft_printf("start: %u, end: %u\n", start, end);
}

void	init_asm(t_asm *d, int ac, char **av)
{
	d->n_players = 0;
	d->fd = 0;
	d->n_lines = 0;
	d->n_labels = 0;
	d->debug = false;
	d->head.magic = COREWAR_EXEC_MAGIC;
	d->head.prog_size = 0;
	d->buf = NULL;
	d->labels = NULL;
	ft_bzero(d->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(d->head.comment, COMMENT_LENGTH + 1);
	validate(d, ac, av);
	count_lines_labels(d);
}
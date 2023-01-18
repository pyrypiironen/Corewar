/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:20:07 by abackman          #+#    #+#             */
/*   Updated: 2023/01/18 17:52:29 by abackman         ###   ########.fr       */
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

	start = lseek(d->fd, 0, SEEK_SET);
	end = lseek(d->fd, end, SEEK_END);
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
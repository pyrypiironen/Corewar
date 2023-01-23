/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:20:07 by abackman          #+#    #+#             */
/*   Updated: 2023/01/23 18:03:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

// in t_asm: keep a track of which line we are at
// functions: islabel(char *str) isstatement(char *str)

static int	check_label(t_asm *d, char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (buf[i] == '#')
			break ;
		while (buf[i] && buf[i] == ' ')
			i++;
		while (buf[i] && ft_strchr(LABEL_CHARS, (int)buf[i]))
			i++;
		if (i && ft_strchr(LABEL_CHARS, (int)buf[i-1]) && \
		buf[i] && buf[i] == ':')
		{
			d->n_labels++;
			break ;
		}
		else
			i++;
	}
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i - (i > 0));
}

static void	count_lines_labels(t_asm *d)
{
	size_t	i;

	i = 0;
	while (d->buf[i])
	{
		while (d->buf[i] && d->buf[i] == ' ')
			i++;
		if (d->buf[i] && d->buf[i] == '\n')
			d->n_lines++;
		else if (d->buf[i])
			i += check_label(d, &d->buf[i]);

		i++;
	}
	//ft_printf("lines: %u\nlabels: %u\n", d->n_lines, d->n_labels);
}

void	init_asm(t_asm *d, int ac, char **av)
{
	d->n_players = 0;
	d->fd = 0;
	d->n_lines = 1;
	d->n_labels = 0;
	d->head.magic = COREWAR_EXEC_MAGIC;
	d->head.prog_size = 0;
	d->buf = NULL;
	d->labels = NULL;
	d->row = 0;
	d->col = 0;
	ft_bzero(d->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(d->head.comment, COMMENT_LENGTH + 1);
	validate(d, ac, av);
	count_lines_labels(d);
	init_label_table(d);
}
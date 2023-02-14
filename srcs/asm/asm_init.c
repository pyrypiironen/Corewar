/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:20:07 by abackman          #+#    #+#             */
/*   Updated: 2023/02/14 15:23:18 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	check_label(t_asm *d, char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (buf[i] == '#')
			break ;
		while (ft_iswhitespace((int)buf[i]))
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
		while (ft_iswhitespace((int)d->buf[i]))
			i++;
		if (d->buf[i])
			i += check_label(d, &d->buf[i]);

		i++;
	}
	//ft_printf("lines: %u\nlabels: %u\n", d->n_lines, d->n_labels);
}

void	init_asm(t_asm *d, int ac, char **av)
{
	d->labels = NULL;
	d->statements = NULL;
	d->buf = NULL;
	d->tokens = NULL;
	d->n_players = 0;
	d->fd = 0;
	d->code_size = 0;
	d->n_labels = 0;
	d->head.magic = COREWAR_EXEC_MAGIC;
	d->head.prog_size = 0;
	d->row = 1;
	d->col = 1;
	d->i = 0;
	d->unref_labels = false;
	ft_bzero(d->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(d->head.comment, COMMENT_LENGTH + 1);
	ft_bzero(d->code, CHAMP_MAX_SIZE + 1);
	validate(d, ac, av);
	count_lines_labels(d);
	//init_label_table(d);
}
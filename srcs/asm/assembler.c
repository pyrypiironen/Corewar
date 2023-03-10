/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:42 by abackman          #+#    #+#             */
/*   Updated: 2023/03/13 19:31:00 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	init_asm(t_asm *d, int ac, char **av)
{
	d->labels = NULL;
	d->statements = NULL;
	d->tail_statement = NULL;
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
	validate(d, ac, av);
}

static void	parse_flags(t_asm *d, char *str, char *binary)
{
	d->debug = false;
	if (!ft_strcmp(str, "-d"))
		d->debug = true;
	else
	{
		ft_printf("Usage: %s [-d] <sourcefile.s>\n", binary);
		exit(EXIT_FAILURE);
	}
}

/*
** Frees allocated memory, prints given error message and exits.
*/

void	memdel_exit_asm(t_asm *d, void *mem, char *str)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	if (mem != NULL)
		ft_memdel(&mem);
	if (d)
		free_asm(d);
	exit(EXIT_FAILURE);
}

/*
** Frees allocated memory, prints given error message and exits.
*/

void	exit_asm(t_asm *d, char *str)
{
	if (d)
		free_asm(d);
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_asm	d;
	int		i;

	i = 0;
	if (ac == 1 || !ft_strstr(av[ac - 1], ".s"))
	{
		ft_printf("Usage: %s [-d] <sourcefile.s>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	while (++i < (ac - 1))
		parse_flags(&d, av[i], av[0]);
	init_asm(&d, ac, av);
	lexer(&d);
	close(d.fd);
	write_file(&d, av[ac - 1]);
	free_asm(&d);
	return (0);
}

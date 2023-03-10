/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/03/10 15:23:06 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Frees linked list of tokens.
*/

static void	free_tokens(t_oken *tokens)
{
	t_oken	*next;
	t_oken	*cur;

	cur = tokens;
	while (cur)
	{
		next = cur->next;
		if (cur->str != NULL)
			ft_strdel(&cur->str);
		free(cur);
		cur = NULL;
		cur = next;
	}
}

/*
** Frees linked list of statements.
*/

static void	free_statements(t_stat *statements)
{
	t_stat	*tmp;
	t_stat	*next;

	tmp = statements;
	while (tmp)
	{
		next = tmp->next;
		ft_strdel(&tmp->label);
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

/*
** Frees hash table of labels.
*/

static void	free_labels(t_lab **labels, size_t size)
{
	size_t	i;
	t_lab	*tmp;
	t_lab	*next;

	i = 0;
	while (i < size)
	{
		tmp = labels[i];
		while (tmp != NULL)
		{
			next = tmp->next;
			ft_strdel(&tmp->name);
			free(tmp);
			tmp = NULL;
			tmp = next;
		}
		i++;
	}
	free(labels);
	labels = NULL;
}

/*
** Frees all dynamically allocated memory.
*/

void	free_asm(t_asm *d)
{
	ft_strdel(&d->buf);
	if (d->labels)
		free_labels(d->labels, d->n_labels);
	if (d->tokens)
		free_tokens(d->tokens);
	free_statements(d->statements);
	if (d->fd)
		close(d->fd);
}

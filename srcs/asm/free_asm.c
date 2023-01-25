/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/25 12:00:10 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	free_tokens(t_oken *tokens)
{
	t_oken	*next;
	t_oken	*cur;

	cur = tokens;
	while (cur)
	{
		next = cur->next;
		ft_strdel(&cur->str);
		free(cur);
		cur = NULL;
		cur = next;
	}
}

static void	free_labels(t_lab **labels, size_t size)
{
	size_t	i;
	t_lab	*tmp;
	t_lab	*next;

	i = 0;
	while (i < size)
	{
		tmp = labels[i];
		while (tmp)
		{
			next = tmp->next;
			ft_strdel(&tmp->name);
			ft_memdel((void **)&tmp);
			tmp = next;
		}
		i++;
	}
	ft_memdel((void **)labels);
}

void	free_asm(t_asm *d)
{
	if (d->buf != NULL)
		ft_strdel(&d->buf);
	if (d->labels)
		free_labels(d->labels, d->n_labels);
	if (d->tokens)
		free_tokens(d->tokens);
	if (d->fd)
		close(d->fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/20 15:36:43 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

//free labels hashtable, buffer
static void	free_buffer(char **buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		ft_strdel(&(buf[i++]));
	ft_memdel(buf);
}

static void	free_labels(t_lab **labels, int size)
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
			ft_memdel(&tmp);
			tmp = next;
		}
		i++;
	}
	ft_memdel(labels);
}

void	free_asm(t_asm *d)
{
	if (d->buf)
		free_buffer(d->buf);
	if (d->labels)
		free_labels(d->labels, d->n_labels);
}
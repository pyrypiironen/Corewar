/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:26:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/23 14:52:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	free_buffer(char *buf)
{
	//size_t	i;

	//i = 0;
	//while (buf[i])
	//	ft_strdel(&(buf[i++]));
	ft_printf("d->buf: %p\n", &buf);
	ft_strdel(&buf);
	buf = NULL;
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
		free_buffer(d->buf);
	if (d->labels)
		free_labels(d->labels, d->n_labels);
	if (d->fd)
		close(d->fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:59:55 by abackman          #+#    #+#             */
/*   Updated: 2023/01/23 14:00:12 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static unsigned long	label_hash(char *name, int size)
{
	unsigned long	hash;
	unsigned long	i;

	hash = 5381;
	i = 0;
	while (name[i])
		hash = ((hash << 5) + hash) + name[i++];
	return (hash % size);
}

void	add_label_to_table(t_asm *d, t_lab *new)
{
	t_lab			*tmp;
	unsigned long	index;

	index = label_hash(new->name, d->n_labels);
	tmp = d->labels[index];
	if (!tmp)
	{
		d->labels[index] = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	init_label_table(t_asm *d)
{
	t_lab	**labels;
	size_t	i;

	labels = (t_lab **)malloc(d->n_labels * sizeof(t_lab *));
	if (!labels)
		exit_asm(d, MALLOC_ERR);
	i = 0;
	while (i < d->n_labels)
		d->labels[i++] = NULL;
}

t_lab	*get_label(t_asm *d, char *name)
{
	t_lab			*tmp;
	unsigned long	index;

	index = label_hash(name, d->n_labels);
	tmp = d->labels[index];
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
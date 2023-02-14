/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:59:55 by abackman          #+#    #+#             */
/*   Updated: 2023/02/14 16:12:14 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static unsigned long	label_hash(char *name, int size)
{
	unsigned long	hash;
	unsigned long	i;

	hash = 5381;
	i = 0;
	//ft_printf("\tlabel_hash [%s]\n", name);
	while (name[i])
		hash = ((hash << 5) + hash) + name[i++];
	return (hash % size);
}

void	add_label_to_table(t_asm *d, t_lab *new)
{
	t_lab			*tmp;
	unsigned long	index;

	//printf("\t*label* %p\n", new->name);
	index = label_hash(new->name, d->n_labels);
	if (d->labels[index] == NULL)
	{
		//printf("add label [%p]\n", new);
		d->labels[index] = new;
		return ;
	}
	tmp = d->labels[index];
	while (tmp->next != NULL)
	{
		//printf("add label [%p]\n", tmp->next);
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	init_label_table(t_asm *d)
{
	size_t	i;

	d->labels = (t_lab **)malloc(d->n_labels * sizeof(t_lab *));
	if (!d->labels)
		exit_asm(d, MALLOC_ERR);
	i = 0;
	while (i < d->n_labels)
		d->labels[i++] = NULL;
	//ft_printf("Label table initialized! %u [%p]\n", d->n_labels, d->labels);
}

t_lab	*get_label(t_asm *d, char *name, size_t len)
{
	t_lab			*tmp;
	unsigned long	index;

	index = label_hash(name, d->n_labels);
	tmp = d->labels[index];
	while (tmp)
	{
		//ft_printf("%s\n", tmp->name);
		if (!ft_strncmp(name, tmp->name, len))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
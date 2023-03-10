/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:59:55 by abackman          #+#    #+#             */
/*   Updated: 2023/03/10 15:29:32 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Generates a number within 'size' range, with 'name' as a pseudo-random seed.
*/

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

/*
** Puts 'new' into the hash table, if there is already a struct in the index
** it will add 'new' to the end of the linked list at index.
*/

void	add_label_to_table(t_asm *d, t_lab *new)
{
	t_lab			*tmp;
	unsigned long	index;

	index = label_hash(new->name, d->n_labels);
	if (d->labels[index] == NULL)
	{
		d->labels[index] = new;
		return ;
	}
	tmp = d->labels[index];
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

/*
** Allocates memory for the hash table and initializes all indexes to NULL.
*/

void	init_label_table(t_asm *d)
{
	size_t	i;

	d->labels = (t_lab **)malloc(d->n_labels * sizeof(t_lab *));
	if (!d->labels)
		exit_asm(d, MALLOC_ERR);
	i = 0;
	while (i < d->n_labels)
		d->labels[i++] = NULL;
}

/*
** Attempts to find a label with matching 'name' in the hash table. If found,
** returns that label. If not, NULL is returned.
*/

t_lab	*get_label(t_asm *d, char *name, size_t len)
{
	t_lab			*tmp;
	unsigned long	index;

	index = label_hash(name, d->n_labels);
	tmp = d->labels[index];
	while (tmp)
	{
		if (!ft_strncmp(name, tmp->name, len) && len == ft_strlen(tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

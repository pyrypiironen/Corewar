/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:15:59 by abackman          #+#    #+#             */
/*   Updated: 2021/11/25 14:08:24 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (content == NULL || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else if (new)
	{
		new->content = (void *)malloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

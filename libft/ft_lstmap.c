/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:38:29 by abackman          #+#    #+#             */
/*   Updated: 2021/11/26 19:37:54 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freelist(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		free(tmp->content);
		free(tmp);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!tmp)
		return (NULL);
	head = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp->next)
		{
			ft_freelist(head);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (head);
}

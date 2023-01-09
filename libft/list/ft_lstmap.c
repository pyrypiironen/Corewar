/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:22:17 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/22 17:22:18 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;

	if (lst == NULL || !f)
		return (NULL);
	tmp = (*f)(lst);
	if (tmp == NULL)
		return (NULL);
	fresh = tmp;
	while (lst->next != NULL)
	{
		tmp->next = (*f)(lst->next);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:01:09 by abackman          #+#    #+#             */
/*   Updated: 2021/11/25 14:33:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*next;

	if (alst == NULL)
		return ;
	new = (*alst);
	while (new)
	{
		next = new->next;
		ft_lstdelone(&new, del);
		new = next;
	}
	*alst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:33:32 by abackman          #+#    #+#             */
/*   Updated: 2021/11/26 19:53:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size < 1)
		return (NULL);
	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	else
	{
		ft_bzero(mem, size);
		return (mem);
	}
}

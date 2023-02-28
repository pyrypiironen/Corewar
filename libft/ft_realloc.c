/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:21:15 by abackman          #+#    #+#             */
/*   Updated: 2022/10/03 16:06:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t size)
{
	void	*new;

	if (ptr == NULL || ptr_size == 0)
		return (ft_memalloc(size));
	if (size < 1)
		return (ptr);
	new = ft_memalloc(size);
	if (new == NULL)
		return (ptr);
	if (ptr_size > size)
		ptr_size = size;
	ft_memcpy(new, ptr, ptr_size);
	free(ptr);
	return (new);
}

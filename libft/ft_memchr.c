/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:28:16 by abackman          #+#    #+#             */
/*   Updated: 2021/11/10 12:46:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;
	unsigned char	*p;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	p = NULL;
	while (i < n)
	{
		if (src[i] == ch)
		{
			p = &src[i];
			break ;
		}
		i++;
	}
	return (p);
}

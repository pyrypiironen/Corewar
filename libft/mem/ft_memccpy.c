/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:30:05 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/08 12:30:16 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;
	unsigned char	box;

	i = 0;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	box = (unsigned char)c;
	while (i < n)
	{
		*dest = *srce;
		if (*srce == box)
		{
			dest++;
			return (dest);
		}
		i++;
		dest++;
		srce++;
	}
	return (NULL);
}

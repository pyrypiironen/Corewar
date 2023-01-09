/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:22:46 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/07 12:22:49 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	i = 0;
	if (dst == NULL && src == NULL && n > 0)
		return (dst);
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (i < n)
	{
		*dest = *srce;
		i++;
		dest++;
		srce++;
	}
	return (dst);
}

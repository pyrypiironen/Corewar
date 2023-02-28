/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:07 by abackman          #+#    #+#             */
/*   Updated: 2021/11/25 16:00:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (j < len)
	{
		if (src[j] == '\0')
		{
			dst[j] = '\0';
			break ;
		}
		dst[j] = src[j];
		j++;
	}
	if (i < len)
	{
		ft_bzero((dst + j), (len - i));
	}
	return (dst);
}

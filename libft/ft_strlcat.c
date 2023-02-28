/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:52:13 by abackman          #+#    #+#             */
/*   Updated: 2021/11/30 15:47:46 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = ft_strlen(dst);
	j = 0;
	l = i + ft_strlen(src);
	if (dstsize < i || dstsize < 1)
		return (dstsize + ft_strlen(src));
	while ((i + j) < (dstsize - 1) && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize != 0)
		dst[i + j] = '\0';
	return (l);
}

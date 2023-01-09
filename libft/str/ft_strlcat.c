/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:42:13 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/04 16:44:31 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	res;

	i = 0;
	d_len = ft_strlen(dst);
	res = ft_strlen(src) + ft_strlen(dst);
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while ((d_len + i + 1 < dstsize) && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (res);
}

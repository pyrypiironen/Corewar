/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:32:46 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/07 15:32:47 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*buf;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	buf = (unsigned char *)ft_memalloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	ft_memcpy(buf, src, len);
	ft_memcpy(dst, buf, len);
	ft_memdel((void **)(&buf));
	return (dst);
}

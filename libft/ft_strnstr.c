/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:35:56 by abackman          #+#    #+#             */
/*   Updated: 2022/08/09 12:58:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkstrn(const char *h, const char *n, size_t i, size_t len)
{
	size_t	j;

	while (i < len && h[i] != '\0')
	{
		j = 0;
		if (h[i] == n[j])
		{
			while (h[i + j] == n[j] && (i + j) < len)
			{
				j++;
				if (n[j] == '\0')
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		res;

	if (needle[0] == '\0')
		return ((char *)haystack);
	res = ft_checkstrn(haystack, needle, 0, len);
	if (res >= 0)
		return ((char *)&haystack[res]);
	else
		return (NULL);
}

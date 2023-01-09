/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:08:44 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/08 19:08:46 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0 || ft_strcmp((char *)needle, "") == 0)
		return ((char *)(haystack));
	while (i < len)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0
			&& (len - i) >= ft_strlen(needle))
			return ((char *)(haystack));
		haystack++;
		i++;
	}
	return (NULL);
}

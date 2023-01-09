/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:34:52 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/08 18:35:09 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (ft_strlen(haystack) >= ft_strlen(needle))
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}

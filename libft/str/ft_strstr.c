/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:34:52 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/24 14:30:00 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_checkstr(const char *h, const char *n, size_t i, size_t j)
{
	if (n[j] == '\0')
		return (0);
	while (h[i] != '\0')
	{
		j = 0;
		if (h[i] == n[j])
		{
			while (h[i + j] == n[j])
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

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		res;

	res = ft_checkstr(haystack, needle, 0, 0);
	if (res == 0 || needle == NULL)
		return ((char *)haystack);
	if (res > 0)
		return ((char *)&haystack[res]);
	else
		return (NULL);
}
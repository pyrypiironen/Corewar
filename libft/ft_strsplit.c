/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:38:48 by abackman          #+#    #+#             */
/*   Updated: 2022/08/03 13:54:19 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_nextword(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = ft_strsub(s, 0, i);
	return (str);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**str;
	size_t	words;
	size_t	k;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	words = ft_countwords(s, c);
	k = 0;
	while (k < words && s)
	{
		while (*s == c && *s != '\0')
			s++;
		str[k] = add_nextword(s, c);
		if (str[k] == NULL)
			return ((char **)ft_free_arr(str, k - 1));
		while (*s != c && *s != '\0')
			s++;
		k++;
	}
	str[k] = NULL;
	return (str);
}

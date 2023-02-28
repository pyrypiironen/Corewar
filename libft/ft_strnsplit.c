/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:02 by abackman          #+#    #+#             */
/*   Updated: 2022/10/10 14:11:58 by abackman         ###   ########.fr       */
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

char	**ft_strnsplit(const char *s, char c, size_t *n)
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
	*n = k;
	return (str);
}

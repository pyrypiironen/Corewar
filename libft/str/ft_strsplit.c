/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:15:39 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/19 12:15:42 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	start;
	size_t	delimiter;
	int		i;
	char	**ret;

	delimiter = 0;
	i = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (ret == NULL || s == 0)
		return (ft_freearray(ret, 0));
	while (s[delimiter] == c)
		delimiter++;
	start = delimiter;
	while (s[start])
	{
		while (s[delimiter] != c && s[delimiter] != '\0')
			delimiter++;
		ret[i++] = ft_strsub(s, start, (delimiter - start));
		if (ret[i - 1] == NULL)
			return (ft_freearray(ret, i));
		while (s[delimiter] == c)
			delimiter++;
		start = delimiter;
	}
	return (ret);
}

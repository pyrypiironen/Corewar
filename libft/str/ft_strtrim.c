/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:19 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/18 15:22:21 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	last;

	if (s == NULL)
		return (NULL);
	i = 0;
	last = ft_strlen(s);
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i++;
	while ((*(s + last) == '\0' || *(s + last) == ' ' || *(s + last) == '\t' \
		|| *(s + last) == '\n') && last != i)
		last--;
	return (ft_strsub(s, i, last - i + 1));
}

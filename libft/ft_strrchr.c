/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:23:34 by abackman          #+#    #+#             */
/*   Updated: 2021/11/16 18:29:35 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	p = NULL;
	while (j > i && s[j] != c)
	{	
		j--;
	}
	if (s[j] == c)
	{
		p = (char *)&s[j];
		return (p);
	}
	else
	{
		return (NULL);
	}
}

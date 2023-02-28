/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:45:04 by abackman          #+#    #+#             */
/*   Updated: 2021/11/23 16:10:24 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n > 0)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]) && n > 0)
		{
			i++;
			n--;
		}
		if (s1[i] == s2[i] && n > 0)
			return (1);
		else if (s1[i - 1] == s2[i - 1] && n == 0)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

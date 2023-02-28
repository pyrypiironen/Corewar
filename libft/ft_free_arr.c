/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:56:43 by abackman          #+#    #+#             */
/*   Updated: 2022/09/19 16:18:33 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr(char **str, size_t size)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		if (str[i] != NULL)
		{
			ft_bzero(str[i], ft_strlen((const char *)str[i]));
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
	return (NULL);
}

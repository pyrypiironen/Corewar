/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:16:06 by abackman          #+#    #+#             */
/*   Updated: 2022/10/05 14:41:50 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_arr2(char ***str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (*str[i])
	{
		free(*str[i]);
		*str[i] = NULL;
		i++;
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

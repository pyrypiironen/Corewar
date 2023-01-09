/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:17:27 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/25 13:17:30 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freearray(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_bzero(arr[i], ft_strlen(arr[i]));
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

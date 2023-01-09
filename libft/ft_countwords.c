/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:38:05 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/24 18:38:07 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_iswhitespace((char)str[i]) == 1)
			i++;
		if (str[i])
			count++;
		while (str[i] && ft_iswhitespace((char)str[i]) == 0)
			i++;
	}
	return (count);
}

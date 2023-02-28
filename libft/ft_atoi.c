/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:54:14 by abackman          #+#    #+#             */
/*   Updated: 2021/11/29 18:24:36 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				pos;
	unsigned long	res;

	i = 0;
	res = 0;
	pos = 1;
	while ((str[i] >= '\b' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		pos = -1 * (str[i] - '-' + 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 9223372036854775807 && pos == 1)
			return (-1);
		if (res > 9223372036854775807 && pos == -1)
			return (0);
		i++;
	}
	return ((int)(res)*pos);
}

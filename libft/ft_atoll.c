/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:43:42 by abackman          #+#    #+#             */
/*   Updated: 2022/07/08 14:53:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int					i;
	long long			pos;
	unsigned long long	res;

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
		if (res > 18446744073709551615ULL && pos == 1)
			return (-1);
		if (res > 18446744073709551615ULL && pos == -1)
			return (0);
		i++;
	}
	return ((long long)res * pos);
}

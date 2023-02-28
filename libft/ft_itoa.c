/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:19:59 by abackman          #+#    #+#             */
/*   Updated: 2022/08/09 12:57:50 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_posnum(long num, size_t len, char *str)
{
	str[len--] = '\0';
	while (num > 0)
	{
		str[len] = ((num % 10) + '0');
		num /= 10;
		len--;
	}
	return (str);
}

static char	*ft_negnum(long num, size_t len, char *str)
{
	num *= -1;
	str[0] = '-';
	str[len--] = '\0';
	while (len > 0 && num > 0)
	{
		str[len] = ((num % 10) + '0');
		num /= 10;
		len--;
	}
	return (str);
}

static char	*ft_zeronum(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	num;

	if (n == 2147483647)
		num = 2147483647;
	else if (n == -2147483648)
		num = -2147483648;
	else
		num = (long)n;
	length = ft_longlen(num);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num == 0)
		str = ft_zeronum(str);
	else if (num < 0)
		str = ft_negnum(num, length, str);
	else
		str = ft_posnum(num, length, str);
	return (str);
}

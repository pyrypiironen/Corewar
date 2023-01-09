/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:24:05 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/21 16:24:07 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long n, int base)
{
	int		i;
	char	arr[64];
	char	*hexa;

	i = 0;
	hexa = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		arr[i] = hexa[n % base];
		i++;
		n = n / base;
	}
	arr[i] = '\0';
	return (ft_strduprev(arr));
}

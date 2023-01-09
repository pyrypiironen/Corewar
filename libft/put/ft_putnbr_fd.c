/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:15:56 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/20 19:15:58 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		arr[20];
	long	k;

	i = 0;
	k = n;
	if (k < 0)
	{
		k = k * -1;
		ft_putchar_fd('-', fd);
	}
	arr[i] = k % 10 + '0';
	i++;
	while (k / 10 > 0)
	{
		k = k / 10;
		arr[i] = (k % 10 + '0');
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd((char)arr[i], fd);
		i--;
	}
}

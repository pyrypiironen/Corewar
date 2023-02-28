/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:22:23 by abackman          #+#    #+#             */
/*   Updated: 2021/11/25 16:18:43 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int				i;
	unsigned char	ch;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ch = (unsigned char)s[i];
		write(1, &ch, 1);
		i++;
	}
}

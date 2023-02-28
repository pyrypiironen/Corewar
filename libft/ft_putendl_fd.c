/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:07:54 by abackman          #+#    #+#             */
/*   Updated: 2021/11/23 16:07:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int				i;
	unsigned char	ch;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ch = (unsigned char)s[i];
		write(fd, &ch, 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:38 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/08 16:07:40 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	box;

	str = (char *)s;
	box = (char)c;
	while (*str != box)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

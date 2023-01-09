/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:59:51 by ppiirone          #+#    #+#             */
/*   Updated: 2021/11/11 16:00:06 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(*res) * (size + 1));
	if (res == NULL)
		return (NULL);
	ft_memset(res, '\0', size + 1);
	return (res);
}

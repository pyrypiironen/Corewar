/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:50:29 by abackman          #+#    #+#             */
/*   Updated: 2022/09/27 12:22:51 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *content, size_t content_size)
{
	if (content_size > 0 && content != NULL)
	{
		free(content);
		content = NULL;
		content_size = 0;
	}
}

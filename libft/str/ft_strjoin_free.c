/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:04:48 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/22 15:04:50 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	y;
	char	*res;

	i = 0;
	y = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
		return (s2);
	if (s1 != NULL && s2 == NULL)
		return (s1);
	res = (char *)malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	free(s1);
	free(s2);
	return (res);
}

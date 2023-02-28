/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:12:35 by abackman          #+#    #+#             */
/*   Updated: 2022/07/07 12:17:41 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*strnull(t_print *p, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (str == NULL && p->precision != 0)
	{
		tmp = ft_strdup("(null)");
	}
	else
	{
		tmp = (char *)malloc(1 * sizeof(char));
		tmp[0] = '\0';
	}
	return (tmp);
}

char	*zerostr(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void	str_reverse(char *str)
{
	char	tmp;
	int		i;
	int		j;

	tmp = 0;
	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
}

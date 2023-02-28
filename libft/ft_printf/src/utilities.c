/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:35 by abackman          #+#    #+#             */
/*   Updated: 2023/02/27 13:06:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_struct(t_print *print)
{
	if (print == NULL)
		return ;
	else if (print != NULL)
	{
		if (print->str != NULL)
		{
			free(print->str);
			print->str = NULL;
		}
		free(print);
		print = NULL;
	}
}

char	*ft_strchr_int(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_int(s);
	while (i <= j)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
** Helper function for strjoin_pro
*/

static char	*strjoin_error(char	*str1, char *str2, int n)
{
	if (n % 2 == 1)
		ft_strdel(&str1);
	if (n >= 2)
		ft_strdel(&str2);
	return (NULL);
}

/*
** Like strjoin, but giving the option of freeing the argument strings.
** n = 1: free str1,
** n = 2: free str2,
** n = 3: free both.
*/

char	*strjoin_pro(char *str1, char *str2, int n)
{
	int		i;
	int		j;
	char	*str;

	if (str1 == NULL || str2 == NULL)
		return (strjoin_error(str1, str2, n));
	i = (ft_strlen_int(str1) + ft_strlen_int(str2));
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (strjoin_error(str1, str2, n));
	j = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[i] = '\0';
	if (n % 2 == 1)
		ft_strdel(&str1);
	if (n >= 2)
		ft_strdel(&str2);
	return (str);
}

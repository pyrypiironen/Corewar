/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:37:42 by abackman          #+#    #+#             */
/*   Updated: 2022/11/15 13:11:31 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_addline(char **line, char **buf, const int fd)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (buf[fd][len] != '\n' && buf[fd][len] != '\0')
		len++;
	if (buf[fd][len] == '\0')
	{
		if (len == 0)
			return (0);
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
	}
	else
	{
		*line = ft_strsub(buf[fd], 0, len);
		tmp = ft_strdup(buf[fd] + len + 1);
		free(buf[fd]);
		buf[fd] = tmp;
	}
	return (1);
}

static char	*strjoin_plus(char *str1, char str2[])
{
	size_t	i;
	size_t	j;
	char	*str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	i = (ft_strlen(str1) + ft_strlen(str2));
	str = (char *)malloc((i + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
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
	free(str1);
	return (str);
}

static int	ft_return(char **line, char **buf, const int fd, int r_bytes)
{
	if (r_bytes < 0)
		return (-1);
	else if (r_bytes == 0 && buf[fd] == NULL)
		return (0);
	else
		return (ft_addline(line, buf, fd));
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[FD_SIZE];
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;
	int			r_bytes;

	if (fd < 0 || BUFF_SIZE < 1 || fd > FD_SIZE || line == NULL)
		return (-1);
	ft_bzero(tmp, BUFF_SIZE + 1);
	r_bytes = read(fd, tmp, BUFF_SIZE);
	while (r_bytes > 0)
	{
		if (buf[fd])
		{
			tmp2 = strjoin_plus(buf[fd], tmp);
			buf[fd] = tmp2;
		}
		else
			buf[fd] = ft_strdup(tmp);
		if (ft_strchr(buf[fd], '\n'))
			break ;
		ft_bzero(tmp, BUFF_SIZE + 1);
		r_bytes = read(fd, tmp, BUFF_SIZE);
	}
	return (ft_return(line, buf, fd, r_bytes));
}

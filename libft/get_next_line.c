/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:32:55 by ppiirone          #+#    #+#             */
/*   Updated: 2021/12/05 15:32:57 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	read_fd(const int fd, char **line, char *arr[FD_SIZE]);
static	int	take_line(const int fd, char **line, char *arr[FD_SIZE], int end);
static	int	take_last(const int fd, char **line, char *arr[FD_SIZE], int end);

int	get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE];

	if (read(fd, arr[0], 0) < 0 || !line || fd >= FD_SIZE - 1 || fd < 0 \
		|| BUFF_SIZE < 1)
		return (-1);
	arr[FD_SIZE - 1] = "1";
	if (take_line(fd, line, arr, 1) == -1)
	{
		ft_strdel(&(arr)[fd]);
		return (-1);
	}
	if (ft_strcmp(arr[FD_SIZE - 1], "0") == 0)
	{
		*line = NULL;
		return (0);
	}
	return (1);
}

static	int	read_fd(const int fd, char **line, char *arr[FD_SIZE])
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	bytes_read = read(fd, buf, BUFF_SIZE);
	buf[bytes_read] = '\0';
	if (bytes_read > 0)
	{
		tmp = ft_strjoin(arr[fd], buf);
		if (tmp == NULL)
			return (-1);
		free(arr[fd]);
		arr[fd] = tmp;
		return (take_line(fd, line, arr, 1));
	}
	else if (bytes_read < 0)
		return (-1);
	return (take_line(fd, line, arr, 0));
}

static int	take_line(const int fd, char **line, char *arr[FD_SIZE], int end)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((arr[fd]) && arr[fd][i])
	{
		if (arr[fd][i] == '\n')
		{
			arr[fd][i] = '\0';
			*line = ft_strdup(arr[fd]);
			if (*line == NULL)
				return (-1);
			tmp = ft_strdup(&(arr)[fd][i + 1]);
			if (tmp == NULL)
			{
				free(*line);
				return (-1);
			}
			free(arr[fd]);
			arr[fd] = tmp;
			return (1);
		}
		i++;
	}
	return (take_last(fd, line, arr, end));
}

static	int	take_last(const int fd, char **line, char *arr[FD_SIZE], int end)
{
	if (end == 0)
	{
		if (!arr[fd])
		{
			arr[FD_SIZE - 1] = "0";
			return (0);
		}
		*line = ft_strdup(arr[fd]);
		if (*line == NULL)
			return (-1);
		if (arr[fd][0] == '\0')
			arr[FD_SIZE - 1] = "0";
		ft_bzero(arr[fd], ft_strlen(arr[fd]));
		return (0);
	}
	else
		return (read_fd(fd, line, arr));
}

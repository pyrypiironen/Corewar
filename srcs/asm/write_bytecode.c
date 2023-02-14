/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:32 by abackman          #+#    #+#             */
/*   Updated: 2023/02/14 18:34:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	small_to_big_endian(int value, uint8_t size)
{
	int	ret;

	ret = 0;
	if (size == 2)
	{
		ret = (0x00ff & value) << 8;
		ret |= (0xff00 & value) >> 8;
		return (ret);
	}
	ret = (0x0000ff00 & value) << 8;
	ret |= (0x00ff0000 & value) >> 8;
	ret |= (0x000000ff & value) << 24;
	ret |= (0xff000000 & value) >> 24;
	return (ret);
}

void	write_file(t_asm *d, char *file)
{
	char	*filename;
	size_t	len;
	int		fd;

	filename = NULL;
	len = ft_strlen(file) - 2;
	file[len] = '\0';
	filename = ft_strjoin(file, ".cor");
	if (!filename)
		exit_asm(d, MALLOC_ERR);
	ft_printf("[%s]\n", filename);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd = -1)
		exit_asm(d, WRITE_FILE_ERR);
	//write_bytecode
	ft_strdel(&filename);
	close(fd);
}
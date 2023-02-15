/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:32 by abackman          #+#    #+#             */
/*   Updated: 2023/02/15 12:31:56 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	small_to_big_endian(int value, uint8_t size)
{
	int	ret;

	ret = 0;
	if (size != 2 && size != 4)
		return (-1);
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

//static void	write_bytecode(t_asm *d)
//{}

static void	write_header(t_asm *d, int fd)
{
	uint32_t	data;

	data = small_to_big_endian(d->head.magic, 4);
	write(fd, &data, 4);
	write(fd, d->head.prog_name, PROG_NAME_LENGTH);
	data = 0;
	write(fd, &data, 4);
	data = small_to_big_endian((int)d->code_size, 4);
	write(fd, &data, 4);
	write(fd, d->head.comment, COMMENT_LENGTH);
	//magic
	//name
	//size
	//comment
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
	write_header(d, fd);
	//write_bytecode
	ft_strdel(&filename);
	close(fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:32 by abackman          #+#    #+#             */
/*   Updated: 2023/02/16 14:44:38 by abackman         ###   ########.fr       */
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

static void	write_arg(t_stat *cur, int fd, int cur_arg)
{
	int32_t	dir_data;
	int16_t	ind_data;

	dir_data = 0;
	ind_data = 0;
	if (cur->argtypes[cur_arg] == T_REG)
		write(fd, &cur->args[cur_arg], 1);
	else if (cur->argtypes[cur_arg] == T_DIR && \
	g_op_tab[cur->opcode].direct_size == 4)
	{
		dir_data = small_to_big_endian(cur->args[cur_arg], DIR_SIZE);
		write(fd, &dir_data, DIR_SIZE);
	}
	else
	{
		ind_data = small_to_big_endian(cur->args[cur_arg], IND_SIZE);
		write(fd, &ind_data, IND_SIZE);
	}
}

static void	write_bytecode(t_asm *d, int fd)
{
	uint8_t	data;
	int		i;
	t_stat	*tmp;

	data = 0;
	tmp = d->statements;
	while (tmp)
	{
		i = 0;
		write(fd, &g_op_tab[tmp->opcode].op_code, 1);
		if (tmp->has_res)
			write(fd, &tmp->rescode, 1);
		while (i < g_op_tab[tmp->opcode].expected_arg_count)
			write_arg(tmp, fd, i++);
		tmp = tmp->next;
	}
}

static void	write_header(t_asm *d, int fd)
{
	uint32_t	data;

	data = small_to_big_endian(d->head.magic, 4);
	write(fd, &data, 4);
	if (d->head.prog_name[0] == 1)
		d->head.prog_name[0] = 0;
	write(fd, d->head.prog_name, PROG_NAME_LENGTH);
	data = 0;
	write(fd, &data, 4);
	data = small_to_big_endian((int)d->code_size, 4);
	write(fd, &data, 4);
	if (d->head.comment[0] == 1)
		d->head.comment[0] = 0;
	write(fd, d->head.comment, COMMENT_LENGTH);
	data = 0;
	write(fd, &data, 4);
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
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_asm(d, WRITE_FILE_ERR);
	write_header(d, fd);
	write_bytecode(d, fd);
	ft_printf("Writing output program to %s\n", filename);
	if (d->debug && d->code_size > CHAMP_MAX_SIZE)
		ft_printf("Warning: the champion code written to %s may be too large!\n\
		Your champion: [%lu] bytes, provided virtual machine takes [%lu] bytes.\
		\n", filename, d->code_size, CHAMP_MAX_SIZE);
	ft_strdel(&filename);
	close(fd);
}

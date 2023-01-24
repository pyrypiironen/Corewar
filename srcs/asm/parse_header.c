/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:41 by abackman          #+#    #+#             */
/*   Updated: 2023/01/24 18:14:50 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	clean_buf(t_asm *d, char *line)
{
	while (line[d->i] && ft_iswhitespace((int)line[d->i]))
		d->i++;
	if (line[d->i] != '#' && line[d->i] != ';')
		error_asm
}

static void	get_comment(t_asm *d, char *line)
{
	size_t	len;

	len = 0;
	if (d->head.comment[0])
		error_asm(d, line, LEX_ERR);
	d->i += 8;
	d->col += 8;
	while (line[d->i] && ft_iswhitespace((int)line[d->i]))
		d->i++;
	if (line[d->i] != '"')
		error_asm(d, NULL, LEX_ERR);
	else
		d->i++;
	if (line[d->i] == '"')
		d->head.comment[0] = 1;
	while (line[d->i] && line[d->i] != '"')
	{
		if (len == COMMENT_LENGTH && line[d->i] != '"')
			error_asm(d, NULL, COM_ERR);
		d->head.comment[len++] = line[d->i++];
	}
	clean_buf(d, line);
}

// start memorizing where the errors occur, replicate original.

static void	get_name(t_asm *d, char *line)
{
	size_t	len;

	len = 0;
	if (d->head.prog_name[0])
		memdel_exit_asm(d, (void *)line, "ERROR: name already given.\n");
	d->i += 5;
	clean_end(d, line);
}

/*
** If name/comment is empty but inside quotes, name[0] will be set to 1.
*/

static void	get_header(t_asm *d)
{
	// READ FROM *BUF until header is validated, then set fd with lseek.
	while (d->buf[d->i])
	{
		if (d->buf[d->i] == '\n')
		{
			d->row++;
			d->col = 0;
		}
		while (ft_iswhitespace((int)d->buf[d->i]))
			d->i++;
		if (!ft_strncmp(&d->buf[d->i], ".name", 5))
			get_name(d, d->buf);
		else if (!ft_strncmp(&d->buf[d->i], ".comment", 8))
			get_comment(d, d->buf);
		else if (d->buf[d->i] && d->buf[d->i] != '#' && d->buf[d->i] != ';')
			error_asm(d, NULL, LEX_ERR);
		if (d->head.prog_name[0] && d->head.comment[0])
			return ;
	}
	error_asm(d, NULL, LEX_ERR);
}

/*
** 1. get labels into label hashtable: each time a label is found, go forward 
** until you found the line/statement it points to, then go back.
** 2. get statements, save in linked list. Save only name of label.
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:53:40 by abackman          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static t_oken	*find_token(t_asm *d, char *str, uint8_t type)
{
	t_oken	*cur;

	cur = d->tokens;
	while (cur)
	{
		if (cur->str && type == DIR && !ft_strcmp(&cur->str[2], str) && \
		cur->type == DIRLAB)
			return (cur);
		else if (cur->str && type == IND && !ft_strcmp(&cur->str[1], str) && \
		cur->type == INDIRLAB)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	label_checker(t_asm *d)
{
	t_stat	*tmp;
	t_lab	*ret;
	size_t	len;
	int		i;

	tmp = d->statements;
	//ft_printf("label_checker\n");
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			if (tmp->arglabel[i])
			{
				len = ft_strlen(tmp->arglabel[i]);
				ret = get_label(d, tmp->arglabel[i], len);
				if (!ret)
					asm_token_error(d, find_token(d, tmp->arglabel[i], \
					tmp->argtypes[i]), NOLABEL_ERR);
			}
		}
		tmp = tmp->next;
	}
}

void	set_token_error_pos(t_asm *d, t_oken *cur)
{
	int		lines;
	int		i;
	char	*pos;

	lines = 1;
	i = 0;
	while (lines < cur->row && d->buf[i])
	{
		if (d->buf[i] == '\n')
			lines++;
		i++;
	}
	pos = ft_strstr(&d->buf[i], cur->str);
	if (!pos)
		return ;
	while (&d->buf[i] != pos)
	{
		if (d->buf[i] == '\n')
		{
			lines++;
			cur->col = 1;
		}
		i++;
		cur->col++;
	}
	cur->row = lines + 1;
}

bool	valid_token_order(t_oken *cur, t_oken *prev)
{
	if (cur != NULL && prev != NULL && cur->type == NEWLINE && \
		prev->type == SEPARATOR)
		return (false);
	if (cur && prev && (cur->type == REG || cur->type == DIR || cur->type == \
	IND || cur->type == DIRLAB || cur->type == INDIRLAB) && prev->type != \
	SEPARATOR && prev->type != OP)
		return (false);
	if (cur && prev && ((cur->type == NAME && prev->type == COMMENT) || \
	(cur->type == COMMENT && prev->type == NAME)))
		return (false);
	if (cur && prev && ((cur->type == OP && prev->type != NEWLINE && \
	prev->type != LABEL)))
		return (false);
	if (cur && prev && (cur->type == LABEL && prev->type != NEWLINE))
		return (false);
	if (cur && prev && (cur->type == SEPARATOR && (prev->type == SEPARATOR ||\
	prev->type == OP)))
		return (false);
	return (true);
}

int	set_error_pos(t_asm *d, int pos, int status)
{
	int	x;
	int	y;
	int	i;

	x = 1;
	y = 1;
	i = 0;
	while (i < pos)
	{
		if (d->buf[i] == '\n')
		{
			y++;
			x = 0;
		}
		i++;
		x++;
	}
	d->row = y;
	d->col = x;
	if (status < 0)
		error_asm(d, NULL, status);
	return (status);
}

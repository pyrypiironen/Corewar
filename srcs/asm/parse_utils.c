/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:53:40 by abackman          #+#    #+#             */
/*   Updated: 2023/02/14 16:06:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static t_oken	*find_token(t_asm *d, char *str, uint8_t type)
{
	t_oken	*cur;
	size_t	start;

	cur = d->tokens;
	start = 0;
	//if (type == IND)
	//	ft_printf("FIND_TOKEN [%s] type [%u]\n", str, type);
	while (cur)
	{
		//ft_printf("CUR STR [%s]\n", cur->str);
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
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			if (tmp->arglabel[i])
			{
				ft_printf("Before get_label %s\n", tmp->arglabel[i]);
				len = ft_strlen(tmp->arglabel[i]);
				ret = get_label(d, tmp->arglabel[i], len);
				ft_printf("After get_label %p\n", ret);
				if (!ret)
					asm_token_error(d, find_token(d, tmp->arglabel[i], \
					tmp->argtypes[i]), NOLABEL_ERR);
			}
		}
		tmp = tmp->next;
	}
}

int	set_error_pos(t_asm *d, int	pos, int status)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/25 17:29:43 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	search_quote(t_asm *d, char *str, int *len, t_type *type)
{
	int	i;

	i = 0;
	//ft_printf("\n\tYES, should be quote: [%c]\n", str[i]);
	d->i++;
	while (str[i] != '"')
	{
		if (str[i] == 0)
		{
			d->i += i;
			set_error_pos(d, d->i, STX_ERR);
		}
		i++;
	}
	//ft_printf(">>[%s]\n>>len %d\n", str, i);
	*len += i;
	ft_printf(" command >>");
	add_token(d, str, *len, *type);
	*len += 1;
	return (1);
}

int	is_command(t_asm *d, char *str, int *len, t_type *type)
{
	int	i;

	i = 0;
	//check the return values, so it skips to the right part..
	if (!ft_strncmp(".name", str, 5))
	{
		i += 5;
		*type = NAME;
	}
	else if (!ft_strncmp(".comment", str, 8))
	{
		i += 8;
		*type = COMMENT;
	}
	else
		return (0);
	while (str[i] && ft_iswhitespace((int)str[i]))
		i++;
	d->i += i;
	if (str[i] == '"')
		return (search_quote(d, &str[i + 1], len, type));
	return (0);
}

int	is_op(char *str, int *len)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		*len = ft_strlen(g_op_tab[i].instruction);
		if (!ft_strncmp(g_op_tab[i].instruction, str, (size_t)*len) && \
		str[*len + 1] && str[*len + 1] == ' ')
		{
			ft_printf(" OP >>");
			return (*len);
		}
		i++;
	}
	*len = 0;
	return (*len);
}

int	is_label(char *str, int *len)
{
	while (str[*len])
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len]) && str[*len] != ':')
		{
			*len = 0;
			return (*len);
		}
		else if (str[*len] == LABEL_CHAR)
		{
			ft_printf(" label >> ");
			return (*len);
		}
		*len += 1;
	}
	*len = 0;
	return (*len);
}

int	is_arg(char *str, int *len, t_type *type)
{
	*type = IND;
	if (str[*len] == DIRECT_CHAR)
	{
		*len += 1;
		*type = DIR;
	}
	if (str[*len] && str[*len] == LABEL_CHAR)
		*len += 1;
	else if (str[*len] && str[*len] == 'r')
	{
		*len += 1;
		*type = REG;
	}
	if (str[*len] && str[*len] == '-')
		*len += 1;
	while (str[*len] && !ft_strchr(" #,\n", (int)str[*len]))
		*len += 1;
	if (*len && str[*len])
	{
		ft_printf(" arg >>");
		return (*len);
	}
	*len = 0;
	return (*len);
}
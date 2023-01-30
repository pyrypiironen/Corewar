/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/30 14:05:00 by abackman         ###   ########.fr       */
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
	//ft_printf(" command >> %u ", *type);
	add_token(d, str, *len, *type);
	*len += 1;
	//ft_printf("[%c]\n", str[*len]);
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
		*len = (int)ft_strlen(g_op_tab[i].instruction);
		if (!ft_strncmp(g_op_tab[i].instruction, str, (size_t)*len))
		{
			//ft_printf(" OP >> ");
			return (*len);
		}
		i++;
	}
	//ft_printf(" NOT OP >> ");
	*len = 0;
	return (*len);
}

int	is_label(char *str, int *len)
{
	while (str[*len])
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len]) && str[*len] != ':')
		{
			//ft_printf(" NOT label >> ");
			*len = 0;
			return (*len);
		}
		else if (str[*len] == LABEL_CHAR)
		{
			//ft_printf(" label >> ");
			*len += 1;
			return (*len);
		}
		*len += 1;
	}
	*len = 0;
	return (*len);
}

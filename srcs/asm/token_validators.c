/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/21 18:25:12 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	found_quote(t_asm *d, char *str, int *len)
{
	int	tmplen;
	
	tmplen = 1;
	while (str[tmplen] && str[tmplen] != '"')
	{
		if (str[tmplen] == '\n')
		{
			d->row++;
			d->col = 1;
		}
		if (str[tmplen] == 0)
		{
			d->i += tmplen;
			set_error_pos(d, d->i, STX_ERR);
		}
		tmplen += 1;
		d->col++;
	}
	//ft_printf(">>[%s]\n>>len %d\n", str, *i);
	*len += tmplen;
	*len += 1;
	return (1);
}

static bool	is_valid_command_str(char *str, int *i, t_type *type)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 5 && !ft_strncmp(NAME_CMD_STRING, str, 5) && \
	(str[5] == '"' || str[5] == ' ' || str[5] == '\t'))
	{
		*i += 5;
		*type = NAME;
		return (true);
	}
	if (len > 8 && !ft_strncmp(COMMENT_CMD_STRING, str, 8) && \
	(str[8] == '"' || str[8] == ' ' || str[8] == '\t'))
	{
		*i += 8;
		*type = COMMENT;
		return (true);
	}
	//ft_printf("NOT A VALID COMMAND STR\n");
	return (false);
}

int	is_command(t_asm *d, char *str, int *len, t_type *type)
{
	int	i;

	i = 0;
	//check the return values, so it skips to the right part..
	if (!is_valid_command_str(str, &i, type))
	//ft_printf(" i: [%i]\n", i);
		return (0);
	while (str[i] && ft_iswhitespace((int)str[i]))
		i++;
	if (str[i] == '"' && found_quote(d, &str[i], len))
	{
		d->i += i;
		//ft_printf("AFTER found_quote\n");
		return (add_token(d, &str[i], *len, *type));
	}
	d->i += i;
	//ft_printf("NOT A VALID COMMAND [%c%c%c]\n", str[i - 2], str[i - 1], str[i]);
	return (0);
}

int	is_op(char *str, int *len)
{
	int	i;

	i = 16;
	while (--i > -1)
	{
		*len = (int)ft_strlen(g_op_tab[i].instruction);
		if (!ft_strncmp(g_op_tab[i].instruction, str, (size_t)*len))
		{
			//ft_printf(" OP >> [%c] ", str[*len]);
			return (*len);
		}
	}
	*len = 0;
	//ft_printf(" NOT OP >> [%c] ", str[*len]);
	return (*len);
}

int	is_label(char *str, int *len)
{
	if (str[*len] == LABEL_CHAR)
		return (0);
	while (str[*len])
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len]) && str[*len] != ':')
		{
			//ft_printf(" NOT label >> [%c] ", str[0]);
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
	//ft_printf("Not label\n");
	*len = 0;
	return (*len);
}

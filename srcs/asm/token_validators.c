/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/03/15 17:35:48 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Validates 'str', attempts to find the second double quote that terminates
** the name.
*/

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
		tmplen += 1;
		d->col++;
	}
	if (str[tmplen] == 0)
	{
		d->i += tmplen;
		set_error_pos(d, d->i, STX_ERR);
	}
	*len += tmplen;
	*len += 1;
	return (1);
}

/*
** Validates 'str', whether it is a valid command string.
*/

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
	return (false);
}

/*
** Validates 'str', both the command itself and the name given after.
*/

int	is_command(t_asm *d, char *str, int *len, t_type *type)
{
	int	i;

	i = 0;
	if (!is_valid_command_str(str, &i, type))
		return (0);
	while (str[i] && ft_strchr(" \t\v", (int)str[i]))
		i++;
	if (str[i] == '"' && found_quote(d, &str[i], len))
	{
		d->i += i;
		return (add_token(d, &str[i], *len, *type));
	}
	else
	{
		d->i += i + *len;
		error_asm(d, NULL, ENDLINE_ERR);
	}
	return (0);
}

/*
** Validates 'str'. Returns the length of the portion considered to be a
** statement, or returns 0 if it does not follow correct statement syntax.
*/

int	is_op(char *str, int *len)
{
	int	i;

	i = 16;
	while (--i > -1)
	{
		*len = (int)ft_strlen(g_op_tab[i].instruction);
		if (!ft_strncmp(g_op_tab[i].instruction, str, (size_t)(*len)))
			return (*len);
	}
	*len = 0;
	return (*len);
}

/*
** Validates 'str'. Returns the length of the portion considered to be a label,
** or returns 0 if it does not follow correct label syntax.
*/

int	is_label(char *str, int *len)
{
	if (str[*len] == LABEL_CHAR)
		return (0);
	while (str[*len])
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len]) && str[*len] != ':')
		{
			*len = 0;
			return (*len);
		}
		else if (str[*len] == LABEL_CHAR)
		{
			*len += 1;
			return (*len);
		}
		*len += 1;
	}
	*len = 0;
	return (*len);
}

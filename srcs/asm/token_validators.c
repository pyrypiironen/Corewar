/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/02/13 17:44:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static int	found_quote(t_asm *d, char *str, int *len)
{
	int	tmplen;
	
	tmplen = 1;
	//d->i++;
	//ft_printf("\n\tYES, should be quote: [%c]\n", str[0]);
	while (str[tmplen] != '"')
	{
		if (str[tmplen] == 0)
		{
			d->i += tmplen;
			set_error_pos(d, d->i, STX_ERR);
		}
		tmplen += 1;
	}
	//ft_printf(">>[%s]\n>>len %d\n", str, *i);
	*len += tmplen;
	//ft_printf(" command >> ");
	*len += 1;
	//d->i += tmplen;
	//ft_printf("[%s]\n", ft_strsub(str, 0, *len));
	return (1);
}

static bool	is_valid_command_str(char *str, int *i, t_type *type)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 5 && !ft_strncmp(NAME_CMD_STRING, str, 5) && \
	(str[5] == '"' || str[5] == ' '))
	{
		*i += 5;
		*type = NAME;
		return (true);
	}
	if (len > 8 && !ft_strncmp(COMMENT_CMD_STRING, str, 8) && \
	(str[8] == '"' || str[8] == ' '))
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
		return (0);
	//ft_printf(" i: [%i]\n", i);
	while (str[i] && ft_iswhitespace((int)str[i]))
		i++;
	if (str[i] == '"' && found_quote(d, &str[i], len))
	{
		d->i += i;
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
			//ft_printf(" OP >> ");
			return (*len);
		}
	}
	//ft_printf(" NOT OP >> ");
	*len = 0;
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
	//ft_printf("Not label\n");
	*len = 0;
	return (*len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/03/10 15:32:13 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Checks the syntax of 'str'. If it is considered a valid registry argument,
** true is returned. If not, false is returned.
*/

static bool	is_reg(char *str, int *len)
{
	int	i;

	i = 0;
	if (str[*len + i] && str[*len + i] == 'r')
		i += 1;
	else
		return (false);
	while (str[*len + i] && !ft_strchr(" \t#;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
			return (false);
		i++;
	}
	*len = *len + i;
	return (true);
}

/*
** Checks the syntax of 'str'. If it is considered a valid label argument,
** true is returned. If not, false is returned.
*/

static bool	is_label_arg(t_asm *d, char *str, int *len)
{
	int	i;

	i = 0;
	if (str[*len] == DIRECT_CHAR)
		i++;
	if (str[*len + i] != LABEL_CHAR)
		return (false);
	else
		i++;
	if (str[*len + i] == '\0')
		set_error_pos(d, *len + i, EOF_ERR);
	while (str[*len + i] && str[*len + i] == ' ')
		i++;
	while (str[*len + i] && !ft_strchr(" \t#;,\n", (int)str[*len + i]))
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len + i]))
			set_error_pos(d, (*len + d->i + i), LEX_ERR);
		i++;
	}
	*len = *len + i;
	return (true);
}

/*
** Checks the syntax of 'str'. If it is considered a valid direct argument,
** true is returned. If not, false is returned.
*/

static bool	is_direct(t_asm *d, char *str, int *len)
{
	int	i;

	i = 1;
	if (str[*len] != DIRECT_CHAR)
		return (false);
	if (str[*len + i] == '\0')
		set_error_pos(d, *len + i, EOF_ERR);
	else if (str[*len + i] == '-')
		i++;
	if (!ft_isdigit((int)str[*len + i]))
		set_error_pos(d, d->i + *len, LEX_ERR);
	while (str[*len + i] && !ft_strchr(" \t#;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
			set_error_pos(d, d->i + *len, LEX_ERR);
		i++;
	}
	*len = *len + i;
	return (true);
}

/*
** Checks the syntax of 'str'. If it is considered a valid indirect argument,
** true is returned. If not, false is returned.
*/

static bool	is_indirect(t_asm *d, char *str, int *len)
{
	int	i;

	i = 0;
	if (str[*len] == '-')
		i++;
	else if (str[*len] == ':')
		i++;
	while (str[*len + i] && !ft_strchr(" \t#;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
			return (false);
		i++;
	}
	if (str[*len + i] == '\0')
		set_error_pos(d, *len + i, EOF_ERR);
	else if (str[*len + i] == '-')
		i++;
	while (str[*len + i] && !ft_strchr(" \t#;,\n", (int)str[*len + i]))
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len + i]))
			set_error_pos(d, *len + i, LEX_ERR);
		i++;
	}
	*len = *len + i;
	return (true);
}

/*
** Checks the syntax of 'str'. If it is considered a valid indirect argument,
** assigns the type of argument to 'type' and returns 0. If not, assigns 'type
** to be VOID and returns 0.
*/

int	is_arg(t_asm *d, char *str, int *len, t_type *type)
{
	if (is_reg(str, len))
		*type = REG;
	else if (is_label_arg(d, str, len))
	{
		*type = DIRLAB;
		if (str[0] == ':')
			*type = INDIRLAB;
	}
	else if (is_direct(d, str, len))
		*type = DIR;
	else if (is_indirect(d, str, len))
			*type = IND;
	if (*type == VOID)
		return (0);
	return (1);
}

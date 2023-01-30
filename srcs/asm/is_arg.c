/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/30 18:19:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static bool	is_reg(char *str, int *len)
{
	int	i;

	i = 0;
	if (str[*len + i] && str[*len + i] == 'r')
		i += 1;
	while (str[*len + i] && !ft_strchr(" #;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
			return (false);
		i++;
	}
	//ft_printf(" IS_REG >> ");
	*len = *len + i;
	return (true);
}

static bool	is_direct_label(t_asm *d, char *str, int *len)
{
	int	i;

	i = 2;
	if (str[*len] != DIRECT_CHAR)
		return (false);
	if (str[*len + 1] != LABEL_CHAR)
		return (false);
	if (str[*len + i] == '\0')
		set_error_pos(d, *len + i, EOF_ERR);
	//ft_printf("IS DIR LAB %i\n", *len);
	while(str[*len + i] && str[*len + i] == ' ')
		i++;
	while (str[*len + i] && !ft_strchr("#;,\n", (int)str[*len + i]))
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len + i]))
			set_error_pos(d, (*len + d->i + i), LEX_ERR);
		i++;
	}
	*len = *len + i;
	//ft_printf(" IS DIRECT LABEL >> ");
	return (true);
}

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
	while (str[*len + i] && !ft_strchr(" #;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
			set_error_pos(d, *len + i, LEX_ERR);
		i++;
	}
	//ft_printf(" IS DIR >> ");
	*len = *len + i;
	return (true);
}

static bool is_indirect(t_asm *d, char *str, int *len)
{
	int	i;

	i = 0;
	if (str[*len] == '-')
		i++;
	while (str[*len + i] && !ft_strchr(" #;,\n", (int)str[*len + i]))
	{
		if (!ft_isdigit((int)str[*len + i]))
		{
			//ft_printf(" NOT DIR >> ");
			return (false);
		}
		i++;
	} 
	if (str[*len + i] == '\0')
		set_error_pos(d, *len + i, EOF_ERR);
	else if (str[*len + i] == '-')
		i++;
	while (str[*len + i] && !ft_strchr(" #;,\n", (int)str[*len + i]))
	{
		if (!ft_strchr(LABEL_CHARS, (int)str[*len + i]))
			set_error_pos(d, *len + i, LEX_ERR);
		i++;
	}
	//ft_printf(" IS INDIR >> ");
	*len = *len + i;
	return (true);
}

int	is_arg(t_asm *d, char *str, int *len, t_type *type)
{
	if (is_reg(str, len))
		*type = REG;
	else if (is_direct_label(d, str, len))
		*type = DIRLAB;
	else if (is_direct(d, str, len))
		*type = DIR;
	else if (is_indirect(d, str, len))
		*type = IND;
	if (*type == VOID)
		return (0);
	return (1);
}
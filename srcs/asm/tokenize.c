/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/25 17:26:49 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for syntax errors.
*/

int	add_token(t_asm *d, char *str, int len, t_type type)
{
	t_oken	*new;
	t_oken	*tmp;

	tmp = d->tokens;
	new = (t_oken *)malloc(sizeof(t_oken));
	if (!new)
		error_asm(d, NULL, MAL_ERR);
	new->next = NULL;
	new->type = type;
	new->row = d->row;
	new->col = d->col;
	new->str = ft_strnew((size_t)len);
	if (!new->str)
		error_asm(d, NULL, MAL_ERR);
	ft_strncpy(new->str, str, (size_t)len);
	ft_printf(" [%s]\n", new->str);
	if (d->tokens == NULL)
	{
		d->tokens = new;
		return (len);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (len);
}

static int	check_type(t_asm *d, char *str)
{
	int		len;
	t_type	type;

	len = 0;
	type = VOID;
	if (str[len] == '\n')
		return (add_token(d, str, 1, NEWLINE));
	else if (str[len] == SEPARATOR_CHAR)
		return (add_token(d, str, 1, SEPARATOR));
	else if (is_op(str, &len))
		return (add_token(d, str, len, OP));
	else if (is_label(str, &len))
		return (add_token(d, str, len, LABEL));
	else if (is_command(d, str, &len, &type))
		return (len);
	else if (is_arg(str, &len, &type))
		return (add_token(d, str, len, type));
	else
		return (set_error_pos(d, d->i, STX_ERR));
}

static int	skip_to_next_line(t_asm *d, char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	//ft_printf("\n>>>SKIP_TO_NEXT: %d\n", str[len]);
	if (!str[len])
		return (EOF_ERR);
	else
		add_token(d, &str[len], 1, NEWLINE);
	len++;
	//*i += len;
	d->row++;
	d->col = 0;
	return (len);
}

void	tokenize(t_asm *d)
{
	int	ret;

	ft_printf("\n* * * Tokenize * * *\n");
	while (d->buf[d->i])
	{
		ret = 0;
		while (ft_iswhitespace((int)d->buf[d->i]))
		{
			d->i++;
			d->col++;
		}
		if (d->buf[d->i] == COMMENT_CHAR || d->buf[d->i] == ALT_COMMENT_CHAR)
			ret = skip_to_next_line(d, &d->buf[d->i]);
		else
			ret = check_type(d, &d->buf[d->i]);
		if (ret == EOF_ERR)
			return ;
		d->i += ret;
		d->col += ret;
	}
}
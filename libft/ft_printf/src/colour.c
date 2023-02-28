/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:52:52 by abackman          #+#    #+#             */
/*   Updated: 2022/07/07 12:30:48 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	exit_colour(t_print *p)
{
	p->ret += write(STDOUT_FILENO, "{", 1);
	return (1);
}

static int	put_colour(t_print *p, const char *format, int i)
{
	if (!ft_strncmp("{eoc}", format, i))
		write(STDOUT_FILENO, RESET, sizeof(RESET));
	else if (!ft_strncmp("{red}", format, i))
		write(STDOUT_FILENO, RED, sizeof(RED));
	else if (!ft_strncmp("{green}", format, i))
		write(STDOUT_FILENO, GREEN, sizeof(GREEN));
	else if (!ft_strncmp("{blue}", format, i))
		write(STDOUT_FILENO, BLUE, sizeof(BLUE));
	else if (!ft_strncmp("{yellow}", format, i))
		write(STDOUT_FILENO, YELLOW, sizeof(YELLOW));
	else if (!ft_strncmp("{purple}", format, i))
		write(STDOUT_FILENO, PURPLE, sizeof(PURPLE));
	else if (!ft_strncmp("{cyan}", format, i))
		write(STDOUT_FILENO, CYAN, sizeof(CYAN));
	else if (!ft_strncmp("{black}", format, i))
		write(STDOUT_FILENO, BLACK, sizeof(BLACK));
	else if (!ft_strncmp("{white}", format, i))
		write(STDOUT_FILENO, WHITE, sizeof(WHITE));
	else
		return (exit_colour(p));
	return (i + 1);
}

int	check_colour(t_print *p, const char	*format)
{
	int	i;

	i = 0;
	while (format[i] != '}' && i < 8 && format[i] != '%')
	{
		if (format[i] == '\0')
			break ;
		i++;
	}
	if (format[i] != '}' || i < 2)
		return (exit_colour(p));
	else
		return (put_colour(p, format, i));
}

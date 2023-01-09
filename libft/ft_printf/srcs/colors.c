/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:11:12 by ppiirone          #+#    #+#             */
/*   Updated: 2022/04/23 17:11:14 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	read_color(const char *format, t_struct *d)
{
	ft_bzero(d->print, 440);
	is_color_1(format, d);
	is_color_2(format, d);
}

void	is_color_1(const char *format, t_struct *d)
{
	if (ft_strncmp(format, "{green}", 7) == 0)
	{
		d->green = 1;
		d->pos = 7;
	}	
	else if (ft_strncmp(format, "{red}", 5) == 0)
	{
		d->red = 1;
		d->pos = 5;
	}	
	else if (ft_strncmp(format, "{yellow}", 8) == 0)
	{
		d->yellow = 1;
		d->pos = 8;
	}	
	else if (ft_strncmp(format, "{blue}", 6) == 0)
	{
		d->blue = 1;
		d->pos = 6;
	}	
	else if (ft_strncmp(format, "{blue2}", 7) == 0)
	{
		d->blue2 = 1;
		d->pos = 7;
	}	
}

void	is_color_2(const char *format, t_struct *d)
{
	if (ft_strncmp(format, "{purple}", 8) == 0)
	{
		d->purple = 1;
		d->pos = 8;
	}	
	else if (ft_strncmp(format, "{black}", 7) == 0)
	{
		d->black = 1;
		d->pos = 7;
	}	
}

void	set_color_start(t_struct *d)
{
	char	*tmp;

	tmp = NULL;
	if (d->green)
		tmp = ft_strjoin("\x1B[32m", d->print);
	else if (d->red)
		tmp = ft_strjoin("\x1B[31m", d->print);
	else if (d->yellow)
		tmp = ft_strjoin("\x1B[33m", d->print);
	else if (d->blue)
		tmp = ft_strjoin("\x1B[36m", d->print);
	else if (d->blue2)
		tmp = ft_strjoin("\x1B[34m", d->print);
	else if (d->purple)
		tmp = ft_strjoin("\x1B[35m", d->print);
	else if (d->black)
		tmp = ft_strjoin("\x1B[30m", d->print);
	ft_strcpy(d->print, tmp);
	free(tmp);
}

void	set_color_end(t_struct *d)
{
	char	*tmp;

	tmp = ft_strjoin(d->print, "\x1B[0m");
	ft_strcpy(d->print, tmp);
	free(tmp);
}

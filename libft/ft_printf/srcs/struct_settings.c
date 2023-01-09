/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:35:12 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/20 16:35:14 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_struct(t_struct *d)
{
	d->ppos = 0;
	d->conv_o = 0;
	d->conv_x = 0;
	d->conv_big_x = 0;
	d->conv_p = 0;
	d->pos = 0;
	d->hash = 0;
	d->zero = 0;
	d->plus = 0;
	d->minus = 0;
	d->space = 0;
	d->width = 0;
	d->padding = -1;
	d->s_pad = 0;
	d->s_pad = 0;
	d->mod_h = 0;
	d->mod_hh = 0;
	d->mod_l = 0;
	d->mod_ll = 0;
	d->mod_big_l = 0;
	d->arg = -1;
	d->arg_o = 0;
	d->rounding = 0.0;
	d->res = 0;
	set_colors(d);
}

void	set_colors(t_struct *d)
{
	d->green = 0;
	d->red = 0;
	d->yellow = 0;
	d->blue = 0;
	d->blue2 = 0;
	d->purple = 0;
	d->black = 0;
}

void	reset_struct(t_struct *d)
{
	d->conv_o = 0;
	d->conv_x = 0;
	d->conv_big_x = 0;
	d->conv_p = 0;
	d->hash = 0;
	d->zero = 0;
	d->plus = 0;
	d->minus = 0;
	d->space = 0;
	d->width = 0;
	d->padding = -1;
	d->s_pad = 0;
	d->s_pad = 0;
	d->mod_h = 0;
	d->mod_hh = 0;
	d->mod_l = 0;
	d->mod_ll = 0;
	d->mod_big_l = 0;
	d->arg = -1;
	d->arg_o = 0;
	d->rounding = 0.0;
}

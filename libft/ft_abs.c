/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:49:34 by abackman          #+#    #+#             */
/*   Updated: 2022/09/27 12:20:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the absolute value of num, cast as a long long integer.
*/

long long	ft_abs(int num)
{
	if (num < 0)
		return ((long long)num * -1);
	else
		return ((long long)num);
}

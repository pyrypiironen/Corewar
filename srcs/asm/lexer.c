/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:50:37 by abackman          #+#    #+#             */
/*   Updated: 2023/01/30 18:25:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

//static void	syntax_checker()
/*
** Goes through the input, cleans it up (removes whitespace and comments) and
** saves the separated words as tokens. Will only check for basic errors.
*/

void	lexer(t_asm *d)
{
	tokenize(d);
	//parse(d);
}
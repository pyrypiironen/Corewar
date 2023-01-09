/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:32 by abackman          #+#    #+#             */
/*   Updated: 2023/01/09 17:17:31 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define  ASSEMBLER_H
# include "libft.h"
# include "op.h"
# include <stdint.h>
# include <fcntl.h>


/*
** Structs
*/

typedef struct s_asm
{
	header_t	head[MAX_PLAYERS];
	int			n_players;
	bool		debug;
}	t_asm;

/*
** Functions
*/

void	exit_asm(t_asm *d, char *str);
void	free_asm(t_asm	*d);
void	parse_flags(t_asm *d, char *str);
void	init_asm(t_asm *d, int ac, char **av);
void	read_file(t_asm *d, int ac, char **av);

#endif

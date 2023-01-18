/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:32 by abackman          #+#    #+#             */
/*   Updated: 2023/01/18 17:28:32 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define  ASSEMBLER_H
# include "../libft/libft.h"
# include "op.h"
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

/*
** Structs
*/

typedef struct s_asm
{
	t_header	head;
	int			fd;
	int			n_players;
	bool		debug;
	char		*buf;
}	t_asm;

typedef struct s_lab
{
	char	*name;
	int		line;
	size_t	bytes;
}
typedef struct s_op
{
	const char	*instruction;
	int			op_code;
	int			arg_type[3];
	int			direct_size;
	int			arg_type_code;
	int			expected_arg_count;
}	t_op;

static const t_op	g_op_tab[] = {
{"live", 1, {T_DIR}, 4, 0, 1},
{"ld", 2, {T_DIR | T_IND, T_REG}, 4, 1, 2},
{"st", 3, {T_REG, T_IND | T_REG}, 4, 1, 2},
{"add", 4, {T_REG, T_REG, T_REG}, 4, 1, 3},
{"sub", 5, {T_REG, T_REG, T_REG}, 4, 1, 3},
{"and", 6, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 4, 1, 3},
{"or", 7, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1, 3},
{"xor", 8, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 4, 1, 3},
{"zjmp", 9, {T_DIR}, 2, 0, 1},
{"ldi", 10, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1, 3},
{"sti", 11, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 2, 1, 3},
{"fork", 12, {T_DIR}, 2, 0, 1},
{"lld", 13, {T_DIR | T_IND, T_REG}, 4, 1, 2},
{"lldi", 14, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 2, 1, 3},
{"lfork", 15, {T_DIR}, 2, 0, 1},
{"aff", 16, {T_REG}, 4, 1, 1},
{NULL, 0, {0}, 0, 0, 0}};

/*
** Functions
*/

void	exit_asm(t_asm *d, char *str);
void	free_asm(t_asm	*d);
void	parse_flags(t_asm *d, char *str);
void	init_asm(t_asm *d, int ac, char **av);
void	validate(t_asm *d, int ac, char **av);
void	read_file(t_asm *d);

#endif
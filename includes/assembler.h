/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:32 by abackman          #+#    #+#             */
/*   Updated: 2023/02/28 14:28:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define  ASSEMBLER_H
# include "../libft/libft.h"
# include "op.h"
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

/* Error messages */
# define MALLOC_ERR "Error: malloc failure.\n"
# define FILE_ERR "Error: invalid file.\n"
# define NAME_ERR "Champion name too long (Max length 128)\n"
# define COMMENT_ERR "Champion comment too long (Max length 2048)\n"
# define ARGCOUNT_ERR_STR "Too many arguments for operation."
# define NO_NL_END_STR "Syntax error - unexpected end of input \
(Did you forget a newline or a double quote?)\n"
# define WRITE_FILE_ERR "Error: could not open file for writing.\n"
# define DOUBLE_CMD_ERR "Error: command already given.\n"
# define SEPARATOR_ERR_STR "Error: separator followed by separator.\n"

/* Error codes */
# define LEX_ERR -42
# define STX_ERR -43
# define EOF_ERR -44
# define COM_ERR -45
# define NAM_ERR -46
# define MAL_ERR -47
# define TYP_ERR -48

# define NAMELEN_ERR -142
# define COMMLEN_ERR -143
# define ARGCOUNT_ERR -144
# define ENDLINE_ERR -145
# define NOLABEL_ERR -146
# define SEPARATOR_ERR -147

/*
** Structs
*/

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

typedef enum e_type
{
	VOID,
	REG,
	DIR,
	IND,
	NAME,
	COMMENT,
	SEPARATOR,
	NEWLINE,
	LABEL,
	OP,
	DIRLAB,
	INDIRLAB
}	t_type;

typedef struct s_oken
{
	struct s_oken	*next;
	t_type			type;
	char			*str;
	int				row;
	int				col;
}	t_oken;

typedef struct s_stat
{
	struct s_stat	*next;
	t_op			op;
	char			*label;
	char			*arglabel[3];
	int				loc;
	int				args[3];
	uint8_t			argtypes[3];
	uint8_t			cur_arg;
	uint8_t			opcode;
	uint8_t			rescode;
	bool			has_res;
	bool			valid;
}	t_stat;

typedef struct s_lab
{
	struct s_lab	*next;
	t_stat			*statement;
	char			*name;
	size_t			line;
	size_t			start;
	size_t			bytes;
}	t_lab;

typedef struct s_asm
{
	t_lab		**labels;
	t_header	head;
	t_oken		*tokens;
	t_stat		*statements;
	t_stat		*tail_statement;
	char		code[CHAMP_MAX_SIZE];
	int			fd;
	int			n_players;
	int			row;
	int			col;
	int			i;
	size_t		code_size;
	size_t		n_labels;
	char		*buf;
	bool		debug;
	bool		unref_labels;
}	t_asm;

/*
** Functions
*/

void	error_asm(t_asm *d, char *line, int status);
void	exit_asm(t_asm *d, char *str);
void	memdel_exit_asm(t_asm *d, void *mem, char *str);
void	free_asm(t_asm *d);
void	validate(t_asm *d, int ac, char **av);
void	write_file(t_asm *d, char *file);

/*
** Lexer functions
*/

void	lexer(t_asm *d);
void	tokenize(t_asm *d);
void	label_checker(t_asm *d);
int		add_token(t_asm *d, char *str, int len, t_type type);
int		is_op(char *str, int *len);
int		is_label(char *str, int *len);
int		is_arg(t_asm *d, char *str, int *len, t_type *type);
int		is_command(t_asm *d, char *str, int *len, t_type *type);
void	token_to_statement(t_asm *d, t_oken *cur, t_oken *prev);
void	save_label(t_asm *d, t_oken *cur, t_oken *prev);
void	save_argument(t_asm *d, t_oken *cur, t_oken *prev, t_stat *dst);
void	save_statement(t_asm **d, t_oken *cur, t_oken *prev);
bool	valid_token_order(t_oken *cur, t_oken *prev);

/*
** Label functions
*/

t_lab	*get_label(t_asm *d, char *name, size_t len);
void	init_label_table(t_asm *d);
void	add_label_to_table(t_asm *d, t_lab *new);
void	add_statement_to_labels(t_asm *d, t_stat *new);

/*
** Translations
*/

void	translate_calculations(t_asm *d);

/*
** Utility functions
*/

int		set_error_pos(t_asm *d, int pos, int status);
void	asm_token_error(t_asm *d, t_oken *cur, int status);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:32:53 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/12 15:32:54 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdio.h> // DELETE, just for real printf

static const char *color_tab[] = {
	"", "\x1B[32m", "\x1B[33m", "\x1B[31m", "\x1B[35m"
};

typedef struct			s_vm_data
{
	unsigned char		arena[MEM_SIZE];
	int					arena_color[MEM_SIZE];
	struct s_player		*players;
	struct s_player		*player_head;
	struct s_carriage	*carriage;
	struct s_carriage	*carriage_head;
	int					player_amount;
	int					winner;			// or pointer to players struct
	int					current_cycle;
	int					cycles_to_die;
	int					cycles_to_check;
	int					check_count;
	int					live_statements;
	int					n_flag;
	int					d_flag;
	int					od_flag;
	int					c_flag;
	int					a_flag; // print actions and dump
}						t_vm_data;

typedef struct			s_carriage
{
	int					id;
	int					carry;
	int			 		cursor;
	int					cursor_copy;
	int					last_live;
	unsigned char		statement;
	int					to_execute;
	int					jump_size;
	int					registrys[REG_NUMBER];
	struct s_carriage	*next;
}						t_carriage;

typedef struct		s_player
{
	int				id;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				code_size;
	unsigned char	*excode;
	int				location;
	struct s_player		*next;
}					t_player;



void	init_core(int argc, char **argv, t_vm_data *d);
void	read_champs(int	argc, char **argv, t_vm_data *d);


//		* * * * * * * * CARRIAGES * * * * * * * *
//		init.c
void	init_carriages(t_vm_data *d);


//		* * * * * * * * PREREQUITES * * * * * * * *
//		arena.c
void	fill_arena(t_vm_data *d);

//		champs.c
int		is_champ( char *argv, t_vm_data *d);
void	init_champ(t_vm_data *d, t_player *champ, char *file);
void	init_ids(t_vm_data *d);
int		check_id(t_player *champ, int id);
void	id_error_check(t_vm_data *d);

//		read_cor.c
void	read_magic(int fd);
void	read_name(t_player *champ, int fd);
void	skip_nulls(int fd);
void	read_excode_size(t_player *champ, int fd);
void	read_comment(t_player *champ, int fd);

//		read_cor_2.c
void	read_excode(t_player *champ, int fd);

//		* * * * * * * * STATEMENTS * * * * * * * *
//		op_add.c
void	op_add(t_carriage *carriage, t_vm_data *d);
void	op_sub(t_carriage *carriage, t_vm_data *d);

//		op_aff.c
void	op_aff(t_carriage *carriage, t_vm_data *d);

//		op_fork.c
void	op_fork(t_carriage *carriage, t_vm_data *d);
void	op_lfork(t_carriage *carriage, t_vm_data *d);
void	copy_carriage(t_carriage *carriage, t_vm_data *d);

//		op_helpers.c
int		is_valid_reg(int position, t_vm_data *d);
int		update_carry(int value);
int		get_4_byte_value(t_vm_data *d, int position);
int		get_2_byte_value(t_vm_data *d, int position, int idx);
void	int_to_arena(t_vm_data *d, int position, int value);

//		op_helpers_2.c
int		count_jump_size(t_carriage *carriage, t_vm_data *d, int	dir_size, \
		int args);
int		move_cursor(t_carriage *carriage, int arg);

//		op_jump.c
void	op_jump(t_carriage *carriage, t_vm_data *d);

//		op_ld.c
void	op_ld(t_carriage *carriage, t_vm_data *d);
void	op_lld(t_carriage *carriage, t_vm_data *d);

//		op_ldi.c
void	op_ldi(t_carriage *carriage, t_vm_data *d);
void	op_lldi(t_carriage *carriage, t_vm_data *d);

//		op_live.c
void	op_live(t_carriage *carriage, t_vm_data *d);

//		op_st.c
void	op_st(t_carriage *carriage, t_vm_data *d);
void	op_sti(t_carriage *carriage, t_vm_data *d);

//		op_bitwise.c
void	op_and(t_carriage *carriage, t_vm_data *d);
void	op_or(t_carriage *carriage, t_vm_data *d);
void	op_xor(t_carriage *carriage, t_vm_data *d);

//		* * * * * * * * THE GAME * * * * * * * *
//		checks.c
void	check(t_vm_data *d);

//		play.c
void	play_the_game(t_vm_data *d);

//		* * * * * * * * HELPERS * * * * * * * *
//		print.c
void	print_error(char *str, int usage);
void	print_dump(t_vm_data *d);
void	print_replica_dump(t_vm_data *d);
void	print_contestants(t_vm_data *d);
void	dump_info(t_vm_data *d);





//		* * * * * * * * TESTS * * * * * * * *
//		prerequite_tests.c
void	print_champs(t_vm_data *d);
void	print_arena(t_vm_data *d);
void	print_carriages(t_vm_data *d);



//		* * * * * * * * DISPATCH TABLE TO STATEMENTS * * * * * * * *
typedef void		(*t_op)(t_carriage *carriage, t_vm_data *d);

static const t_op	g_dispatcher[16] = {
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_jump,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff
};




#endif

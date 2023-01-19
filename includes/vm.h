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

typedef struct		s_vm_data
{
	unsigned char	arena[MEM_SIZE];
	struct s_player	*players;
	struct s_player	*player_head;
	int				player_amount;
	int				last_live;			// or pointer to players struct
	int				cycles_to_die;
	int				live_statements;
	int				n_flag;
	int				d_flag;
	


}					t_vm_data;

typedef struct			s_carriage
{
	int					id;
	int					carry;
	int			 		cursor;
	int					last_live;
	unsigned char		ex_code;
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
	int				position;
	struct s_player		*next;
}					t_player;


void	print_error(char *str, int usage);

void	init_core(int argc, char **argv, t_vm_data *d);
void	read_champs(int	argc, char **argv, t_vm_data *d);



//		* * * * * * * * PREREQUITES * * * * * * * *
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








#endif

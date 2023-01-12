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

typedef struct		s_vm_data
{
	unsigned char	arena[MEM_SIZE];
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
	char			*name;
	char			*comment;
	int				code_size;
	char			*ex_code;
	int				position;
}					t_player;


void	print_error(char *str, int usage);

void	init_core(t_vm_data *d);
void	read_champs(int	argc, char **argv, t_vm_data *d);








#endif

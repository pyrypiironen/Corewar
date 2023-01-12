/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:10:13 by ppiirone          #+#    #+#             */
/*   Updated: 2023/01/12 18:10:14 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/vm.h"

static int	is_flag(char *argv);
static void	read_flag(t_vm_data *d, char *value);
static int	core_atoi(char *str);

void	read_champs(int	argc, char **argv, t_vm_data *d)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(d, *argv[i]) && i + 1 < argc)
				read_flag(d, argv[++i]);
		else if (is_champ[i] == 1)
			;
		else
			print_error("Wrong usage. Invalid input.", 1);
		i++;
	}
}

static int	is_flag(t_vm_data *d, char *argv)
{
	if (ft_strcmp(argv, "-n") == 0)
	{
		d->n_flag = 42;
		return (1);
	}
	else if (ft_strcmp(argv, "-d") == 0)
	{
		d->d_flag = 42;
		return (1);
	}
	return (0);
	
}

static void	read_flag(t_vm_data *d, char *value)
{
	if (d->n_flag == 42)
		d->n_flag = core_atoi(value); // error check inside here
	else
		d->d_flag = //core_atoi
}

static int	core_atoi(char *str)
{

	
}
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

#include "../../../includes/vm.h"

static int	is_flag(t_vm_data *d, char *argv);
static void	read_flag(t_vm_data *d, char *value);
static int	core_atoi(t_vm_data *d, char *str);

void	read_champs(int argc, char **argv, t_vm_data *d)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(d, argv[i]) && i + 1 < argc)
			read_flag(d, argv[++i]);
		else if (is_champ(argv[i], d) == 1)
			;
		else
			print_error("Wrong usage. Invalid input.", 1);
		i++;
	}
}

static int	is_flag(t_vm_data *d, char *argv)
{
	if (ft_strcmp(argv, "-n") == 0 && d->n_flag == 0)
	{
		d->n_flag = 42;
		return (1);
	}
	else if (ft_strcmp(argv, "-dump") == 0)
	{
		if (d->d_flag != 0)
			print_error("Wrong usage. Only one -dump flag is allowed.", 1);
		d->d_flag = 42;
		return (1);
	}
	return (0);
}

static void	read_flag(t_vm_data *d, char *value)
{
	if (d->n_flag == 42)
		d->n_flag = core_atoi(d, value);
	else
		d->d_flag = core_atoi(d, value);
}

static int	core_atoi(t_vm_data *d, char *str)
{
	unsigned long int	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (unsigned long int)*str - '0';
		if (res > 2147483647)
			print_error("Wrong usage. Flag value is limited to max int.", 1);
		str++;
	}
	if (*str != '\0')
		print_error("Wrong usage. Invalid argument after flag.", 1);
	if (res < 1 && d->n_flag == 42)
		print_error("Wrong usage. Player number can't be smaller than 1.", 1);
	else if (res > d->player_amount && d->n_flag == 42)
		print_error("Wrong usage. Player number can't be bigger than amount of \
players.", 1);
	return ((int)res);
}
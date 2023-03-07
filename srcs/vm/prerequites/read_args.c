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
static int	is_flag_helper(t_vm_data *d, char *argv);
static void	read_flag(t_vm_data *d, char *value);
static int	core_atoi(t_vm_data *d, char *str);

// Main function of reading command line input and .cor files.
// Will initialize champions data structures and flag data.
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
	init_ids(d);
	id_error_check(d);
}

// Return the information if there is the flag on command line input.
static int	is_flag(t_vm_data *d, char *argv)
{
	if (ft_strcmp(argv, "-n") == 0 && d->n_flag == 0)
	{
		d->n_flag = -1;
		return (1);
	}
	else if (ft_strcmp(argv, "-dump") == 0)
	{
		if (d->d_flag != -2 || d->od_flag != -2 || d->c_flag != -2 || \
			d->a_flag != -2)
			print_error("Wrong usage. Only one -dump/-d/-c flag allowed.", 1);
		d->d_flag = -1;
		return (1);
	}
	else if (ft_strcmp(argv, "-d") == 0)
	{
		if (d->d_flag != -2 || d->od_flag != -2 || d->c_flag != -2 || \
			d->a_flag != -2)
			print_error("Wrong usage. Only one -dump/-d/-c flag allowed.", 1);
		d->od_flag = -1;
		return (1);
	}
	else if (is_flag_helper(d, argv))
		return (1);
	return (0);
}

// Just an extension for is_flag function.
static int	is_flag_helper(t_vm_data *d, char *argv)
{
	if (ft_strcmp(argv, "-a") == 0)
	{
		if (d->d_flag != -2 || d->od_flag != -2 || d->c_flag != -2 || \
			d->a_flag != -2)
			print_error("Wrong usage. Only one -dump/-d/-c flag allowed.", 1);
		d->a_flag = -1;
		return (1);
	}
	else if (ft_strcmp(argv, "-c") == 0)
	{
		if (d->d_flag != -2 || d->od_flag != -2 || d->c_flag != -2 || \
			d->a_flag != -2)
			print_error("Wrong usage. Only one -dump/-d/-c flag allowed.", 1);
		d->c_flag = -1;
		return (1);
	}
	return (0);
}

// Read flag value to data_struct. Will be used only when is_flag returns 1.
static void	read_flag(t_vm_data *d, char *value)
{
	if (d->n_flag == -1)
		d->n_flag = core_atoi(d, value);
	else if (d->d_flag == -1)
		d->d_flag = core_atoi(d, value);
	else if (d->od_flag == -1)
		d->od_flag = core_atoi(d, value);
	else if (d->a_flag == -1)
		d->a_flag = core_atoi(d, value);
	else
		d->c_flag = core_atoi(d, value);
}

// Simple version of ft_atoi modified to this project. Also include error
// handling against wrong usage of flags.
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
	if (res < 1 && d->n_flag == -1)
		print_error("Wrong usage. Player number can't be smaller than 1.", 1);
	else if (res > MAX_PLAYERS && d->n_flag == -1)
		print_error("Wrong usage. Player number can't be bigger than \
MAX_PLAYERS.", 1);
	return ((int)res);
}

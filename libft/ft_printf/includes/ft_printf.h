/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiirone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:57:30 by ppiirone          #+#    #+#             */
/*   Updated: 2022/03/07 14:57:31 by ppiirone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>

# define CONVERSION	"cspdiouxXf%b"
# define FLAGS		"#0-+ "
# define SPECIFIERS	"#0-+ .*0123456789hlL"

typedef struct s_struct
{
	char				print[440];
	int					ppos;
	int					pos;
	int					conv_o;
	int					conv_x;
	int					conv_big_x;
	int					conv_p;
	int					hash;
	int					zero;
	int					plus;
	int					minus;
	int					space;
	int					width;
	int					asterix;
	int					padding;
	int					s_pad;
	int					mod_h;
	int					mod_hh;
	int					mod_l;
	int					mod_ll;
	int					mod_big_l;
	int					input_len;
	int					print_len;
	long long			arg;
	unsigned long long	arg_o;
	long double			arg_f;
	long double			rounding;
	int					green;
	int					red;
	int					yellow;
	int					blue;
	int					blue2;
	int					purple;
	int					black;
	int					res;
}						t_struct;

int		ft_printf(const char *format, ...);
int		read_format(const char *format, va_list ap, t_struct *d);
void	check_conversion(const char *format, va_list ap, t_struct *d);
void	flags(const char *format, t_struct *d);
void	width(const char *format, va_list ap, t_struct *d);
int		width_numbers(const char *format, t_struct *d);
void	precision(const char *format, va_list ap, t_struct *d);
void	precision_asterix_check(const char *format, va_list ap, t_struct *d);
void	modifiers(const char *format, t_struct *d);
void	conversion(const char *format, va_list ap, t_struct *d);
void	conversion_bonus(const char *format, va_list ap, t_struct *d);
int		is_conversion(const char *format, t_struct *d);
void	convert_octal(va_list ap, t_struct *d);
void	convert_unsigned_int(va_list ap, t_struct *d);
void	convert_hexadecimal(va_list ap, t_struct *d);
void	convert_pointer(va_list ap, t_struct *d);
void	convert_modulo(t_struct *d);
void	fill_print(t_struct *d, char *print);
void	adjust_left(t_struct *d, char *print);
void	to_lowercase(char *print);
void	read_arg_unsigned(t_struct *d, va_list ap);
int		print_len_unsigned(t_struct *d, int len);
void	plant_arg_unsigned(t_struct *d, char *print, char *input);
void	zero_precision_check_unsigned(char *print, t_struct *d);
void	convert_int(va_list ap, t_struct *d);
void	read_arg(t_struct *d, va_list ap);
int		print_len(t_struct *d);
void	plant_arg(t_struct *d, char *print, char *input);
void	zero_precision_check(t_struct *d, char *print);
void	convert_char(va_list ap, t_struct *d);
void	adjust_left_char(t_struct *d, char *print);
void	fill_print_char(t_struct *d, char *print);
void	convert_string(va_list ap, t_struct *d);
void	fill_print_str(t_struct *d, char *print, char *input);
void	print_len_str(t_struct *d);
void	convert_double(va_list ap, t_struct *d);
void	rounders(t_struct *d);
void	bankers_rounding(t_struct *d, long double banker, char *alpha);
void	read_arg_double(t_struct *d, va_list ap);
int		print_len_double(t_struct *d);
void	fill_print_double(t_struct *d, char *print);
void	plant_arg_double(t_struct *d, char *print, char *input);
int		is_negative(double nbr);
char	*dtoa(int precision, t_struct *d);
char	*fractional_part(long double n, int precision, t_struct *d);
char	*create_fractional(char *arr, long double n, int precision);
void	check_fractional(char *fractional);
void	convert_binary(const char *format, va_list ap, t_struct *d);
void	print_len_binary(t_struct *d);
void	fill_print_binary(t_struct *d, char *print, char *input);
char	*prepare_input(const char *format, va_list ap, t_struct *d);
void	set_struct(t_struct *d);
void	set_colors(t_struct *d);
void	reset_struct(t_struct *d);
void	add_to_print(char *print, t_struct *d);
void	print_it(t_struct *d);
void	read_color(const char *format, t_struct *d);
void	is_color_1(const char *format, t_struct *d);
void	is_color_2(const char *format, t_struct *d);
void	set_color_start(t_struct *d);
void	set_color_end(t_struct *d);

#endif
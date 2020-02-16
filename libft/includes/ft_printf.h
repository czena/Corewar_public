/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:30:17 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 00:40:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef enum	e_flags {
	flag_plus = 1,
	flag_minus = 2,
	flag_space = 4,
	flag_zero = 8,
	flag_hash = 16
}				t_flags;

typedef enum	e_size_type {
	size_l,
	size_ll,
	size_h,
	size_hh,
	size_L,
	size_default
}				t_size_type;

typedef enum	e_type {
	type_u,
	type_d,
	type_i,
	type_x,
	type_X,
	type_o,
	type_f,
	type_c,
	type_p,
	type_s,
	type_percent
}				t_type;

typedef struct		s_print_info
{
	int				flags;
	int				width;
	int				precision;
	t_size_type		size_type;
	t_type			type;
}					t_print_info;

int					ft_printf(const char *format, ...);
int					putll_base(long long num, t_print_info *info);
void				check_flag(t_print_info *info, const char **ptr);
int					ft_atois(const char **str);
void				check_size(t_print_info *info, const char **ptr);
int					check_type(t_print_info *info, const char **ptr);
int					parser(const char *format, va_list params);
int					putnum_base(unsigned long long num, unsigned base,
						t_print_info *info);
char				*ull_base(unsigned long long num, t_print_info *info);
char				*ll_base(long long num, t_print_info *info);
int					print_params(t_print_info *info, va_list params);
int					print_d(t_print_info *info, va_list params);
int					print_u(t_print_info *info, va_list params);
int					print_p(t_print_info *info, va_list params);
int					print_s(t_print_info *info, va_list params);
int					print_c(t_print_info *info, va_list params);
int					print_oxx(t_print_info *info, va_list params);
int					print_oxx_zero_prec(t_print_info *info);
int					print_f(t_print_info *info, va_list params);
int					print_percent(t_print_info *info);
char				*num_base(unsigned long long num, unsigned base,
							t_print_info *info);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:52 by johnavar          #+#    #+#             */
/*   Updated: 2023/09/19 16:54:08 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft.h"

# ifdef __linux__
#  define NNULL "(nil)"
# else
#  define NNULL "0x0"
# endif

typedef struct s_print
{
	int			spec;
	int			width;
	int			left;
	int			zero;
	int			precision;
	int			hash;
	int			space;
	int			plus;
	int			star;
}				t_print;

// ft_printf
int		ft_printf(const char *strf, ...);
int		ft_printf_fd(int fd, const char *format, ...);
// flags
int		ft_parse_flags(const char *format, int i, va_list *ap, t_print *flags);
// ft_printf_utils
t_print	ft_initialize_tab(void);
int		ft_isflag(int c);
int		ft_istype(int c);
int		ft_isspec(int c);
// print_utils
int		ft_print_pad(int fd, int width, int size, int zero);
int		ft_print_s(int fd, char *str);
int		ft_nbr_len(long int n, int base);
int		ft_print_digit(int fd, long n, int base, char mode);
// print_char
int		ft_print_c(int fd, char c);
int		ft_print_char(int fd, char c, t_print *flags);
// print_string
int		ft_print_string(int fd, char *str, t_print *flags);
// print_int
int		ft_print_int(int fd, long n, char spec, t_print *flags);
// print_hex
int		ft_print_hex(int fd, long n, t_print *flags);
// print_ptr
int		ft_print_ptr(int fd, unsigned long int ptr, t_print *flags);
// print_unsigned
int		ft_print_unsigned(int fd, long n, t_print *flags);

#endif

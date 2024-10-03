/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:15:52 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 15:15:55 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_what_to_print(const char *format, va_list args, int len, int i)
{
	if (format[i] == 's')
		len = ft_printstr(va_arg(args, char *), len);
	else if (format[i] == 'c')
		len = ft_printchar(va_arg(args, int), len);
	else if (format[i] == 'd' || format[i] == 'i')
		len = ft_printnbr(va_arg(args, int), len);
	else if (format[i] == 'p')
		len = ft_print_ptr_add(va_arg(args, size_t), len);
	else if (format[i] == 'u')
		len = ft_print_u_nbr(va_arg(args, size_t), len);
	else if (format[i] == 'x')
		len = ft_print_xs(va_arg(args, size_t), len);
	else if (format[i] == 'X')
		len = ft_print_xl(va_arg(args, size_t), len);
	else if (format[i] == '%')
		len = ft_printchar('%', len);
	return (len);
}

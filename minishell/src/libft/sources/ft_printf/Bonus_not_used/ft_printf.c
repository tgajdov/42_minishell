/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:38:03 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 16:28:37 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include "libftprintf.h"

/*int	ft_printchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_printstr(char *str, int len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			len++;
		}
	}
	return (len);
}

int	ft_printnbr(int nb, int len)
{
	int	again;
	int	print;

	if (nb < 0)
	{
		len = ft_printchar('-', len);
		if (nb < -2147483647)
		{
			write(1, "2147483648", 10);
			len += 10;
		}
		else
			len = ft_printnbr(-nb, len);
	}
	else
	{
		again = nb / 10;
		print = nb % 10;
		if (again != 0)
			len = ft_printnbr(again, len);
		len = ft_printchar(print + 48, len);
	}
	return (len);
}

int	ft_print_u_nbr(size_t nb, int len)
{
	int	again;
	int	print;

	again = nb / 10;
	print = nb % 10;
	if (again != 0)
		len = ft_print_u_nbr(again, len);
	len = ft_printchar(print + 48, len);
	return (len);
}

int	ft_print_ptr_add(size_t add, int len)
{
	char	str[25];
	int		temp;
	int		i;

	i = 0;
	len = ft_printstr("0x", len);
	if (!add)
		return (ft_printchar('0', len));
	while (add != 0)
	{
		temp = add % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 87;
		add /= 16;
		i++;
	}
	i--;
	while (i >= 0)
		len = ft_printchar(str[i--], len);
	return (len);
}

int	ft_print_xs(size_t add, int len)
{
	char	str[25];
	int		temp;
	int		i;

	i = 0;
	if (!add)
		return (ft_printchar('0', len));
	while (add != 0)
	{
		temp = add % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 87;
		add /= 16;
		i++;
	}
	i--;
	while (i >= 0)
		len = ft_printchar(str[i--], len);
	return (len);
}

int	ft_print_xl(size_t add, int len)
{
	char	str[25];
	int		temp;
	int		i;

	i = 0;
	if (!add)
		return (ft_printchar('0', len));
	while (add != 0)
	{
		temp = add % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 55;
		add /= 16;
		i++;
	}
	i--;
	while (i >= 0)
		len = ft_printchar(str[i--], len);
	return (len);
}

int	ft_print_xs_xl(const char *format, size_t add, int len, int i)
{
	i++;
	if (format[i] == 'x')
	{
		len = ft_printstr("0x", len);
		len = ft_print_xs( add, len);
	}
	else if (format[i] == 'X')
	{
		len = ft_printstr("0X", len);
		len = ft_print_xl(add, len);
	}
	return (len);
}

int	ft_printplus(int nb, int len)
{
	len = ft_printchar('+', len);
	len = ft_printnbr(nb, len);
	return (len);
}

int	ft_printspace(int nb, int len)
{
	len = ft_printchar(' ', len);
	len = ft_printnbr(nb, len);
	return (len);
}

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
	else if (format[i] == '#' && (format[i+1]  == 'x' || format[i+1]  == 'X'))
		len = ft_print_xs_xl(format, va_arg(args, size_t), len, i);
	else if (format[i] == 'x')
		len = ft_print_xs(va_arg(args, size_t), len);
	else if (format[i] == 'X')
		len = ft_print_xl(va_arg(args, size_t), len);
	else if (format[i] == '%')
		len = ft_printchar('%', len);
	else if (format[i] == '+' && format[i + 1] == 'i')
		len = ft_printplus(va_arg(args, int), len);
	else if (format[i] == ' ' && format[i + 1] == 'i')
		len = ft_printspace(va_arg(args, int), len);
	return (len);
}*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len = ft_what_to_print(format, args, len, ++i);
			if ((format[i] == '#' && (format[i + 1] == 'x'
						|| format[i + 1] == 'X')) || ((format[i] == ' '
						|| format[i] == '+') && (format[i + 1] == 'i')))
				i++;
		}
		else
		{
			len++;
			write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (len);
}

/*int main(void)
{
	int	len;
//	char	*str = "";

	len = ft_printf("%+i", 1234);
	printf("\n%d\n", len);

	len = printf("%+i", 1234);
	printf("\n%d\n", len);
}*/

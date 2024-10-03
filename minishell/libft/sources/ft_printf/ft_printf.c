/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:38:03 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 15:28:43 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
		len = ft_print_xs(va_arg(args, unsigned int), len);
	else if (format[i] == 'X')
		len = ft_print_xl(va_arg(args, unsigned int), len);
	else if (format[i] == '%')
		len = ft_printchar('%', len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = -1;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%')
			len = ft_what_to_print(format, args, len, ++i);
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
	unsigned long long	str = 9223372036854775807LL;

	len = ft_printf(" %X ", str);
	printf("\n%d\n", len);

//	len = printf(" %x ", str);
	printf("\n%d\n", len);
}*/

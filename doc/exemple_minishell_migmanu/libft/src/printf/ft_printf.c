/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:01:25 by johnavar          #+#    #+#             */
/*   Updated: 2023/09/19 16:43:25 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_spec(int fd, char spec, va_list *ap, t_print *flags)
{
	int	count;

	count = 0;
	if (spec == '%')
		count += ft_print_char(fd, '%', flags);
	else if (spec == 'c')
		count += ft_print_char(fd, (char)va_arg(*ap, int), flags);
	else if (spec == 's')
		count += ft_print_string(fd, va_arg(*ap, char *), flags);
	else if (spec == 'd' || spec == 'i')
		count += ft_print_int(fd, (long)(va_arg(*ap, int)), spec, flags);
	else if (spec == 'x' || spec == 'X')
		count += ft_print_hex(fd, (long)(va_arg(*ap, unsigned int)), flags);
	else if (spec == 'p')
		count += ft_print_ptr(fd, (unsigned long)va_arg(*ap, void *), flags);
	else if (spec == 'u')
		count += ft_print_unsigned(
				fd, (long)(va_arg(*ap, unsigned int)), flags);
	return (count);
}

#ifdef __linux__

static int	ft_parse_format(int fd, const char *format, va_list *ap)
{
	int		i;
	int		x;
	int		count;
	t_print	flags;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			flags = ft_initialize_tab();
			x = ft_parse_flags(format, i, ap, &flags);
			if (flags.spec > 0)
				i = x;
			if (format[i] != '\0' && flags.spec > 0 && ft_istype(format[i]))
				count += ft_print_spec(fd, format[i], ap, &flags);
			else if (format[i] != '\0')
				count += ft_print_c(fd, format[i]);
		}
		else
			count += ft_print_c(fd, format[i]);
	}
	return (count);
}

#else

static int	ft_parse_format(int fd, const char *format, va_list *ap)
{
	int		i;
	int		count;
	t_print	flags;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			flags = ft_initialize_tab();
			i = ft_parse_flags(format, i, ap, &flags);
			if (format[i] != '\0' && flags.spec > 0 && ft_istype(format[i]))
				count += ft_print_spec(fd, format[i], ap, &flags);
			else if (format[i] != '\0')
				count += ft_print_char(fd, format[i], &flags);
		}
		else
			count += ft_print_c(fd, format[i]);
	}
	return (count);
}

#endif

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format || *format == '\0')
		return (0);
	count = 0;
	va_start(ap, format);
	count = ft_parse_format(1, format, &ap);
	va_end(ap);
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format || *format == '\0')
		return (0);
	count = 0;
	va_start(ap, format);
	count = ft_parse_format(fd, format, &ap);
	va_end(ap);
	return (count);
}

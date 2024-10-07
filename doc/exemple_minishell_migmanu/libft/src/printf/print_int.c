/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:43:12 by johnavar          #+#    #+#             */
/*   Updated: 2023/09/19 15:49:34 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_wzero(int fd, long n, t_print *flags)
{
	int	count;

	count = 0;
	if (n < 0 && flags->precision == -1)
		count += write(fd, "-", 1);
	else if (flags->plus == 1)
		count += write(fd, "+", 1);
	else if (flags->space == 1)
		count += write(fd, " ", 1);
	return (count);
}

static int	ft_print_i(int fd, long n, char spec, t_print *flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags->zero == 0 || flags->precision >= 0)
			count += write(fd, "-", 1);
	}
	else if (flags->plus == 1 && flags->zero == 0)
		count += write(fd, "+", 1);
	else if (flags->space == 1 && flags->zero == 0)
		count += write(fd, " ", 1);
	if (flags->precision >= 0)
	{
		if (n < 0)
			count += ft_print_pad(
					fd, flags->precision, ft_nbr_len(n, 10) - 1, 1);
		else
			count += ft_print_pad(fd, flags->precision, ft_nbr_len(n, 10), 1);
	}
	if (n < 0)
		count += ft_print_digit(fd, -n, 10, spec);
	else
		count += ft_print_digit(fd, n, 10, spec);
	return (count);
}

static int	ft_print_i_width(int fd, long n, t_print *flags, int base)
{
	int	count;

	count = 0;
	if (flags->precision >= 0 && flags->precision < ft_nbr_len(n, base))
	{
		if (n < 0)
			flags->precision = ft_nbr_len(n, base) - 1;
		else
			flags->precision = ft_nbr_len(n, base);
	}
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		if (n < 0)
			flags->width -= 1;
		count += ft_print_pad(fd, flags->width, 0, 0);
	}
	else
		count += ft_print_pad(fd, flags->width - flags->plus - flags->space,
				ft_nbr_len(n, base), flags->zero);
	return (count);
}

int	ft_print_int(int fd, long n, char spec, t_print *flags)
{
	int		count;

	count = 0;
	if (flags->precision == 0 && n == 0)
	{
		count += ft_print_pad(fd, flags->width, 0, flags->zero);
		return (count);
	}
	if (flags->zero == 1)
		count += ft_print_wzero(fd, n, flags);
	if (flags->left == 1)
		count += ft_print_i(fd, n, spec, flags);
	count += ft_print_i_width(fd, n, flags, 10);
	if (flags->left == 0)
		count += ft_print_i(fd, n, spec, flags);
	return (count);
}

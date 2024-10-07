/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:01:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/19 16:12:55 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_u(int fd, long n, t_print *flags)
{
	int	count;

	count = 0;
	if (flags->precision >= 0)
		count += ft_print_pad(fd, flags->precision,
				ft_nbr_len(n, 10), 1);
	count += ft_print_digit(fd, n, 10, flags->spec);
	return (count);
}

int	ft_print_unsigned(int fd, long n, t_print *flags)
{
	int	count;

	count = 0;
	if (flags->precision == 0 && n == 0)
	{
		count += ft_print_pad(fd, flags->width, 0, flags->zero);
		return (count);
	}
	if (flags->left == 1)
		count += ft_print_u(fd, n, flags);
	if (flags->precision >= 0 && flags->precision < ft_nbr_len(n, 10))
		flags->precision = ft_nbr_len(n, 10);
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		count += ft_print_pad(fd, flags->width, 0, flags->zero);
	}
	else
		count += ft_print_pad(fd, flags->width,
				ft_nbr_len(n, 10), flags->zero);
	if (flags->left == 0)
		count += ft_print_u(fd, n, flags);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:39:30 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/19 15:52:14 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_pad(int fd, int width, int size, int zero)
{
	int	count;

	count = 0;
	while (width - size > 0)
	{
		if (zero)
			count += write(fd, "0", 1);
		else
			count += write(fd, " ", 1);
		width--;
	}
	return (count);
}

int	ft_print_s(int fd, char *str)
{
	int	count;

	if (str == NULL)
		return (write(fd, "(null)", 6));
	count = 0;
	while (str[count])
		count++;
	write(fd, str, count);
	return (count);
}

int	ft_nbr_len(long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_print_digit(int fd, long n, int base, char mode)
{
	int		count;
	char	*symbols;

	if (mode == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(fd, "-", 1);
		return (ft_print_digit(fd, -n, base, mode) + 1);
	}
	else if (n < base)
		return (write(fd, &symbols[n], 1));
	else
	{
		count = ft_print_digit(fd, n / base, base, mode);
		return (count + ft_print_digit(fd, n % base, base, mode));
	}
}

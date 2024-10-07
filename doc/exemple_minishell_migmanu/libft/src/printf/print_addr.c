/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:54:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/09/19 16:08:57 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_addr(int fd, unsigned long int addr)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (addr < 16)
		return (write(fd, &symbols[addr], 1));
	else
	{
		count = ft_print_addr(fd, addr / 16);
		return (count + ft_print_addr(fd, addr % 16));
	}
}

static int	ft_print_p(int fd, unsigned long int p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += ft_print_s(fd, NNULL);
		return (count);
	}
	count += ft_print_s(fd, "0x");
	count += ft_print_addr(fd, p);
	return (count);
}

int	ft_print_ptr(int fd, unsigned long int ptr, t_print *flags)
{
	int	count;

	count = 0;
	if (ptr == 0)
		flags->width -= ft_strlen(NNULL) - 1;
	else
		flags->width -= 2;
	if (flags->left == 1)
		count += ft_print_p(fd, ptr);
	if (count < flags->width)
		count += ft_print_pad(fd, flags->width, ft_nbr_len(ptr, 16), 0);
	if (flags->left == 0)
		count += ft_print_p(fd, ptr);
	return (count);
}

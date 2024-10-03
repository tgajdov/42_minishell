/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:30:55 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 16:01:51 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	again;
	int	print;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -2147483647)
			write(fd, "2147483648", 10);
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		again = n / 10;
		print = n % 10;
		if (again != 0)
			ft_putnbr_fd(again, fd);
		ft_putchar_fd(print + 48, fd);
	}
}

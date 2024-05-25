/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:49:33 by brferran          #+#    #+#             */
/*   Updated: 2023/10/25 15:11:02 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	longueur_nb(int nb)
{
	int	value;

	value = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		value = value * 10;
	}
	return (value);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		longueur;
	char	number;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		longueur = longueur_nb(n);
		while (longueur != 0)
		{
			number = 0;
			number = n / longueur + '0';
			write(fd, &number, 1);
			n = n % longueur;
			longueur = longueur / 10;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:53:58 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 14:49:03 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

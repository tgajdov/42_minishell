/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:55:35 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 14:47:24 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

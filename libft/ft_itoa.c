/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:22:37 by brferran          #+#    #+#             */
/*   Updated: 2023/10/25 14:10:18 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_nb(int nb)
{
	size_t	size;

	size = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	char		*str;
	size_t		size;
	long int	num;

	num = nb;
	size = size_nb(nb);
	if (nb < 0)
	{
		num *= -1;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	*(str + size) = '\0';
	while (size-- > 0)
	{
		*(str + size) = num % 10 + '0';
		num = num / 10;
	}
	if (nb < 0)
		*(str + 0) = '-';
	return (str);
}

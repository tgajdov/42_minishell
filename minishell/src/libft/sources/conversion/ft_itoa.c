/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:02:29 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 15:56:32 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa(int n)
{
	char			*tab;
	int				len;
	unsigned int	newn;

	newn = n;
	len = ft_intlen(n);
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (n == 0)
		tab[0] = 48;
	if (n < 0)
	{
		tab[0] = '-';
		newn *= (-1);
	}
	while (newn > 0)
	{
		tab[--len] = newn % 10 + 48;
		newn /= 10;
	}
	return (tab);
}

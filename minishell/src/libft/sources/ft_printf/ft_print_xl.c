/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:58:39 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 15:30:53 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_print_xl(unsigned int add, int len)
{
	char	str[25];
	int		temp;
	int		i;

	i = 0;
	if (!add)
		return (ft_printchar('0', len));
	while (add != 0)
	{
		temp = add % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 55;
		add /= 16;
		i++;
	}
	i--;
	while (i >= 0)
		len = ft_printchar(str[i--], len);
	return (len);
}

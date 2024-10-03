/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:46 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 16:01:06 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (len != 0)
	{
		str[i] = c;
		len--;
		i++;
	}
	return (b);
}

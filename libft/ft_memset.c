/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:34:03 by brferran          #+#    #+#             */
/*   Updated: 2023/10/24 14:38:56 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ptr;
	unsigned char	*str;
	int				i;

	ptr = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		str[i] = ptr;
		len--;
		i++;
	}
	return (str);
}

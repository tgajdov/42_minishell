/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:59:32 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 16:00:02 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*str2;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	str2 = (char *)dst;
	str = (char *)src;
	while (n-- != 0)
	{
		*str2++ = *str++;
	}
	return (dst);
}

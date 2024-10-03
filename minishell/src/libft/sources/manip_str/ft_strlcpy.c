/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:37:22 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 16:32:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	index;
	unsigned long	srcsize;

	index = 0;
	srcsize = ft_strlen(src);
	if (dstsize > srcsize + 1)
	{
		while (index < dstsize && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	else if (dstsize != 0)
	{
		while (index < dstsize - 1 && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (srcsize);
}

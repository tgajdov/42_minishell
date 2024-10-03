/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:59:23 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 16:04:55 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	j;
	int				i;
	unsigned long	srcsize;
	size_t			original_dstsize;

	i = 0;
	j = 0;
	srcsize = ft_strlen(src);
	original_dstsize = ft_strlen(dst);
	while (dst[i])
		i++;
	if (dstsize <= original_dstsize)
		return (srcsize + dstsize);
	while ((j < dstsize - original_dstsize - 1) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (srcsize + original_dstsize);
}

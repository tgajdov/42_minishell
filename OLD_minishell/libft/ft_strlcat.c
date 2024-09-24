/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:01:25 by brferran          #+#    #+#             */
/*   Updated: 2023/10/24 17:44:03 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	res;

	dstlen = ft_strlen((const char *)dst);
	srclen = ft_strlen(src);
	i = 0;
	res = 0;
	if (dstsize > dstlen)
		res = dstlen + srclen;
	else
		res = dstsize + srclen;
	while (src[i] != '\0' && dstsize > (dstlen + 1))
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (res);
}

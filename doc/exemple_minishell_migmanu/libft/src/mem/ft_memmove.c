/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:14:46 by johnavar          #+#    #+#             */
/*   Updated: 2023/07/04 17:09:55 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	dest = (char *)dst;
	source = (char *)src;
	if (dest >= source)
	{
		while (len)
		{
			len--;
			*(dest + len) = *(source + len);
		}
		return (dst);
	}
	while (len)
	{
		*dest++ = *source++;
		len--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:54 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 18:12:56 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	old_j;

	i = 0;
	j = 0;
	DEBUG("je suis dans strnstr");
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		old_j = j;
		if (j == len)
			return (NULL);
		while (haystack[j] == needle[i] && j < len)
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack + (j - i));
			i++;
			j++;
		}
		j = old_j + 1;
		i = 0;
	}
	return (NULL);
}

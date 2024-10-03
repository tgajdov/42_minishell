/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:19:50 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 16:32:03 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	strlen;
	char	*ptr;

	if (!s)
		return (0);
	j = 0;
	strlen = (size_t)ft_strlen(s) - start;
	if (len < strlen)
		strlen = len;
	if ((start > (size_t)ft_strlen(s)) || (len == 0))
		ptr = malloc(sizeof(char));
	else
		ptr = malloc((strlen + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (start < (size_t)ft_strlen(s))
	{
		while (strlen--)
			ptr[j++] = s[start++];
	}
	ptr[j] = '\0';
	return (ptr);
}

/* Si mon start est tres lointain,
 * je dois trv un moyen de ne pas allouer atutant de memoire,
 * car la il y a trop de memoire allouee
 * exemple si je dois faire une copie de 50 char
 * au char 950 de ma string, je lui alloue quand meme
 * 1000 emplacement*/

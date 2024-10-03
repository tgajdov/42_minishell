/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:52:01 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 15:59:43 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s11;
	char	*s22;
	size_t	i;

	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s11[i] != (unsigned char)s22[i])
			return ((unsigned char)s11[i] - (unsigned char)s22[i]);
		i++;
	}
	return (0);
}

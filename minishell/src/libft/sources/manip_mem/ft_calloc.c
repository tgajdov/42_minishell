/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:05 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 18:05:27 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*adresse_calloc;
	unsigned long	i;

	i = 0;
	adresse_calloc = malloc(count * size);
	if (!adresse_calloc)
		return (NULL);
	while (i < count * size)
	{
		adresse_calloc[i] = 0;
		i++;
	}
	return (adresse_calloc);
}

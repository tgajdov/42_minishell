/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:36:24 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 16:31:36 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_size_set_debut(const char *s1, char const *set)
{
	size_t	size_set;
	size_t	i;
	size_t	j;

	i = 0;
	size_set = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
			size_set++;
		else if (s1[i] != set[j] && set[j] == '\0')
			break ;
		i++;
	}
	return (size_set);
}

size_t	ft_size_set_fin(const char *s1, char const *set)
{
	size_t	size_set;
	size_t	size_s1;
	size_t	i;
	size_t	j;

	size_set = 0;
	size_s1 = ft_strlen(s1);
	i = size_s1 - 1;
	while (size_set < size_s1)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
			size_set++;
		else if (s1[i] != set[j] && set[j] == '\0')
			break ;
		i--;
	}
	return (size_set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	size_t	size_set_debut;
	size_t	size_set_fin;
	char	*new_s;

	size_s1 = ft_strlen(s1);
	size_set_debut = ft_size_set_debut(s1, set);
	size_set_fin = ft_size_set_fin(s1, set);
	if (size_set_debut == size_set_fin && size_set_debut == size_s1
		&& size_set_fin == size_s1)
	{
		new_s = ft_calloc(1, sizeof(char));
		return (new_s);
	}
	new_s = ft_substr(s1, size_set_debut,
			(size_s1 - size_set_fin - size_set_debut));
	return (new_s);
}

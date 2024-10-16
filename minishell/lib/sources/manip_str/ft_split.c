/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:04:59 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:47:26 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i++]);
	}
	if (tab)
		free(tab);
}

size_t	ft_cw(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

size_t	ft_skip_repeat(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

size_t	ft_iterate(char const *s, char c, size_t iterator, size_t *start)
{
	iterator += ft_skip_repeat(s + iterator, c);
	*start = iterator;
	while (s[iterator] != c && ft_strlen(s) > iterator++)
		;
	return (iterator);
}

char	**ft_split(char const *s, char c)
{
	size_t	iterator;
	size_t	start;
	size_t	tab_iter;
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab_iter = 0;
	tab = ft_calloc((ft_cw(s, c)) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	iterator = 0;
	while (iterator < ft_strlen(s) && tab_iter < ft_cw(s, c))
	{
		iterator = ft_iterate(s, c, iterator, &start);
		tab[tab_iter] = ft_substr(s, start, iterator - start);
		if (tab[tab_iter++] == NULL)
		{
			ft_free_tab(tab);
			return (NULL);
		}
	}
	tab[tab_iter] = 0;
	return (tab);
}

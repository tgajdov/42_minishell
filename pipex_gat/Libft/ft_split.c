/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:04:59 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/30 16:03:07 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	str_i;
	char	**tab;

	str_i = 0;
	tab = ft_calloc((ft_cw(s, c)) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) && str_i <= (ft_cw(s, c) + 1))
	{
		i += ft_skip_repeat(s + i, c);
		start = i;
		len = 0;
		while (s[i] != c && ft_strlen(s) > i++)
			len++;
		if (str_i < ft_cw(s, c))
			tab[str_i++] = ft_substr(s, start, len);
		else
			tab[str_i] = 0;
	}
	return (tab);
}

/*Je dois modifier la foction pour que lorsqu'une allocation
 * de ft_substr echoue, toute la ft_split doit arreter,
 * free les espaces deja allouer et retourner 0*/

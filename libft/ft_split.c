/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:47:08 by brferran          #+#    #+#             */
/*   Updated: 2023/10/25 14:10:09 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char const c, char sep)
{
	if (sep == (char)c)
		return (1);
	return (0);
}

static int	wordlen(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], sep))
		i++;
	return (i);
}

static int	wordcount(char const *str, char sep)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str[i], sep))
			i++;
		if (str[i] != '\0')
		{
			count++;
			len = wordlen(str + i, sep);
			i = i + len;
		}
	}
	return (count);
}

static char	*ft_strdup_w_size(char const *str, int size)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = (char)str[i];
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	k = 0;
	size = wordcount(s, c);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		while (s[k] && is_sep(s[k], c))
			k++;
		if (s[k] == '\0')
			break ;
		j = wordlen(s + k, c);
		dest[i] = ft_strdup_w_size(s + k, j);
		k = k + j;
		i++;
	}
	dest[size] = NULL;
	return (dest);
}

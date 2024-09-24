/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:29:03 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 17:11:56 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	tab_slen(char **tab)
{
	int	i;
	int	t;
	int	slen;

	t = 0;
	slen = 0;
	while (tab[t])
	{
		i = 0;
		while (tab[t][i++])
			slen++;
		t++;
	}
	return (slen);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0')
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	search_occurence(char *str1, char *str2)
{
	int	i;
	int	j;
	int	mem;

	i = 0;
	while (str1[i])
	{
		j = 0;
		mem = i;
		while (str1[mem] == str2[j])
		{
			mem++;
			j++;
		}
		if (str2[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

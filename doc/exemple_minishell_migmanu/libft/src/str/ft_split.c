/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:15:24 by johnavar          #+#    #+#             */
/*   Updated: 2023/07/04 17:22:46 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	words_counter(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*worddup(const char *str, int start, int finish)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = finish - start;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = str[start + i];
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**strs;

	strs = malloc((words_counter(str, c) + 1) * sizeof(char *));
	if (!str || !strs)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			strs[j++] = worddup(str, index, i);
			index = -1;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
}

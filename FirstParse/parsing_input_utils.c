/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:28:56 by brianferran       #+#    #+#             */
/*   Updated: 2024/05/21 14:46:36 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_words(char *str, int i, char *delimiters)
{
	int		end;
	int		len;
	char	*dest;

	end = i;
	while (str[end] != '\0' && strrchr(delimiters, str[end]) == NULL)
		end++;
	len = end - i;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest = ft_strncpy(dest, &str[i], len);
	dest[len] = '\0';
	return (dest);
}

char	*get_quotes(char *str, int i, t_token *token)
{
	char	*dest;
	int		j;
	int		k;

	j = 0;
	k = 0;
	check_quotes(str[i], token);
	if (token->quotes != 0)
	{
		while (token->quotes != 0)
		{
			j++;
			check_quotes(str[i + j], token);
		}
		dest = malloc(sizeof(char) * (j + 1));
		if (!dest)
			return (NULL);
		while (k <= j)
			dest[k++] = str[i++];
		dest[k] = '\0';
		return (dest);
	}
	return (NULL);
}

char	*get_symbols(char *str, int i)
{
	char	*dest;

	if (str[i] == '<' && str[i + 1] == '<')
		dest = ft_strdup("<<");
	else if (str[i] == '>' && str[i + 1] == '>')
		dest = ft_strdup(">>");
	else if (str[i] == '<' && str[i - 1] != '<')
		dest = ft_strdup("<");
	else if (str[i] == '>' && str[i - 1] != '>')
		dest = ft_strdup(">");
	else
		return (NULL);
	return (dest);
}

int	is_space(char *str, int i)
{
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (1);
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

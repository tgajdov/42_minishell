/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:18:53 by brianferran       #+#    #+#             */
/*   Updated: 2024/05/24 18:38:06 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_realloc2(char *new_arg, t_token *token)
{
	char	**new_environ;
	int		i;

	i = tablen(token->argument) + 2;
	new_environ = malloc(i * sizeof(char *));
	if (!new_environ)
		return (NULL);
	i = 0;
	while (token->argument[i] != NULL)
	{
		new_environ[i] = ft_strdup(token->argument[i]);
		i++;
	}
	new_environ[i++] = ft_strdup(new_arg);
	new_environ[i] = NULL;
	free_tab(token->argument);
	return (new_environ);
}

int	ft_strcasecmp(char *s1, char *s2, size_t i)
{
	int		c1;
	int		c2;
	size_t	compt;

	compt = 0;
	while ((*s1 || *s2) && compt < i)
	{
		c1 = ft_tolower(*s1);
		c2 = ft_tolower(*s2);
		if (c1 != c2)
			return (c1 - c2);
		s1++;
		s2++;
		compt++;
	}
	return (0);
}

static char	*get_cmdcopy(char *str, int i, char *dest, t_token *token)
{
	char	*copy;
	char	*joined;

	copy = NULL;
	joined = NULL;
	if (get_symbols(str, i) != NULL)
	{
		copy = get_symbols(str, i);
		joined = ft_strjoin(dest, copy);
	}
	else if (get_quotes(str, i, token) != NULL)
	{
		copy = get_quotes(str, i, token);
		joined = ft_strjoin(dest, copy);
	}
	else
	{
		copy = get_words(str, i, " <>|\n");
		joined = ft_strjoin(dest, copy);
	}
	free(dest);
	return (joined);
}

static char	*get_cmd2(char *str, int i, t_token *token)
{
	char	*temp;

	temp = get_words(str, i, " <>|\n");
	token->cmd = ft_strdup(temp);
	free(temp);
	return (get_words(str, i, " <>|\n"));
}

int	get_cmd(char *str, int i, t_token *token)
{
	char	*dest;
	int		len;

	if (get_symbols(str, i) != NULL)
	{
		dest = get_symbols(str, i);
		token->operator = ft_strdup(dest);
	}
	else if (get_quotes(str, i, token) != NULL)
	{
		dest = get_quotes(str, i, token);
		while (!(is_space(str, ft_strlen(dest)))
			&& (str[ft_strlen(dest)] != '\0'))
			dest = get_cmdcopy(str, ft_strlen(dest), dest, token);
		token->cmd = ft_strdup(dest);
	}
	else
		dest = get_cmd2(str, i, token);
	len = is_echon(str, i, token);
	if (dest == NULL)
		len = 0;
	else if (len == 0)
		len = ft_strlen(dest);
	free(dest);
	return (len);
}

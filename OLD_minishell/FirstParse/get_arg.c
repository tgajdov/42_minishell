/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:22:53 by brianferran       #+#    #+#             */
/*   Updated: 2024/06/11 16:11:53 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_argcopy(char *str, int i, char *dest, t_token *token)
{
	char	*copy;
	char	*joined;

	copy = NULL;
	joined = NULL;
	if (get_quotes(str, i, token) != NULL)
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

static char	*get_arg4(char *str, int i, t_token *token)
{
	char	*dest;

	if ((get_quotes(str, i, token)) != NULL)
	{
		dest = get_quotes(str, i, token);
		while (!(is_space(str, (i + ft_strlen(dest))))
			&& (str[i + ft_strlen(dest)] != '\0')
			&& (get_symbols(str, ft_strlen(dest) + i) == NULL)
			&& str[(ft_strlen(dest) + i)] != '|')
			dest = get_argcopy(str, (i + ft_strlen(dest)), dest, token);
	}
	else
		dest = get_words(str, i, " <>|\0");
	token->argument = ft_realloc2(dest, token);
	return (dest);
}

static char	*get_arg3(char *str, int i, t_token *token)
{
	char	*dest;

	dest = NULL;
	if (get_symbols(str, i) != NULL)
	{
		dest = get_symbols(str, i);
		if (token->operator == NULL)
				token->operator = ft_strdup(dest);
		else
		{
			if (token->next == NULL)
			{
				token->next = initialize_token();
				if (!token->next)
					return (NULL);
			}
			token->next->cmd = token->cmd;
			token->next->argument = token->argument;
			token = token->next;
			token->operator = ft_strdup(dest);
		}
	}
	if (dest == NULL)
		dest = get_arg4(str, i, token);
	return (dest);
}

static char	*get_arg2(char *str, int i, t_token *token)
{
	char	*dest;

	dest = NULL;
	if (token->operator != NULL && token->arg_operator == NULL)
	{
		if (get_symbols(str, i) != NULL)
		{
			dest = get_symbols(str, i);
			token->arg_operator = ft_strdup(dest);
		}
		else if (get_quotes(str, i, token) != NULL)
		{
			dest = get_quotes(str, i, token);
			token->arg_operator = ft_strdup(dest);
		}	
		else
		{
			dest = get_words(str, i, " <>|\n");
			token->arg_operator = ft_strdup(dest);
		}
	}
	if (dest == NULL)
		dest = get_arg3(str, i, token);
	return (dest);
}

int	get_arg(char *str, int i, t_token *token)
{
	char	*dest;
	int		len;

	dest = NULL;
	if (str[i] == '|')
	{
		if (token->next == NULL)
				token->next = initialize_token();
		token = token->next;
		token->pipe = 1;
		dest = ft_strdup("|");
		token->next = initialize_token();
		token = token->next;
	}
	if (dest == NULL)
		dest = get_arg2(str, i, token);
	len = ft_strlen(dest);
	free(dest);
	return (len);
}

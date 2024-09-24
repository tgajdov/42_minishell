/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:39:51 by brianferran       #+#    #+#             */
/*   Updated: 2024/05/21 14:17:56 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_quotes(char c, t_token *token)
{
	if (c == '\'')
	{
		if (token->quotes == 0)
			token->quotes = 1;
		else if (token->quotes == 1)
			token->quotes = 0;
	}
	if (c == '"')
	{
		if (token->quotes == 0)
			token->quotes = 2;
		else if (token->quotes == 2)
			token->quotes = 0;
	}
}

int	check_closedquotes(char *str, t_token *token)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		check_quotes(str[i], token);
		i++;
	}
	if (token->quotes != 0)
		return (0);
	return (1);
}

int	is_echon(char *str, int i, t_token *token)
{
	if (token->cmd != NULL)
	{
		if (ft_strcasecmp(token->cmd, "echo", 4) == 0)
		{
			while (!is_space(str, i) && str[i] != '\0')
				i++;
			while (is_space(str, i) && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (0);
			if (str[i] == '-' && str[i + 1] == 'n')
			{
				free(token->cmd);
				token->cmd = ft_strdup("echo -n");
				return (i + 2);
			}
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:37 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 16:16:00 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	define_tokens(t_token *token, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (is_space(str, i))
			i++;
		if (str[i] == '\0')
			break ;
		while (token->next != NULL)
			token = token->next;
		if (token->cmd == NULL && token->operator == NULL)
		{
			i += get_cmd(str, i, token);
			while (is_space(str, i))
				i++;
			if (str[i] == '\0')
				break ;
		}
		i += get_arg(str, i, token);
	}
}

t_token	*initialize_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->input = NULL;
	token->argument = malloc(sizeof(char **));
	if (!token->argument)
		return (NULL);
	token->argument[0] = NULL;
	token->arg_operator = NULL;
	token->cmd = NULL;
	token->operator = NULL;
	token->pipe = 0;
	token->quotes = 0;
	token->next = NULL;
	return (token);
}

t_token	*parsing_input(char *str)
{
	t_token	*token;

	token = initialize_token();
	if (!token)
		return (NULL);
	if (!(check_closedquotes(str, token)))
	{
		printf("Quotes and double quotes must be closed\n");
		free_token_chain(token);
		return (NULL);
	}
	define_tokens(token, str);
	return (token);
}

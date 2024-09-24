/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:57 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 17:10:45 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **entries)
{
	int	i;

	i = 0;
	if (entries)
	{
		if (entries[i])
		{
			while (entries[i])
				free(entries[i++]);
		}
		free(entries);
	}
}

void	free_alloctrack(t_export *alloctrack)
{
	if (alloctrack)
	{
		if (alloctrack->environ)
			free_tab(alloctrack->environ);
		if (alloctrack->export_env)
			free_tab(alloctrack->export_env);
		if (alloctrack->way)
			free_tab(alloctrack->way);
		free(alloctrack);
	}
}

void	free_token_chain(t_token *token)
{
	t_token	*current;
	t_token	*next_token;

	if (token)
	{
		current = token;
		while (current != NULL)
		{
			next_token = current->next;
			if (current->input)
				free(current->input);
			if (current->cmd)
				free(current->cmd);
			if (current->operator)
				free(current->operator);
			if (current->arg_operator)
				free(current->arg_operator);
			if (current->argument)
				free_tab(current->argument);
			free(current);
			current = next_token;
		}
	}
}

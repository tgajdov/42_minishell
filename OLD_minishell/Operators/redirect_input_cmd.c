/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:52 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:41:38 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_entries(char **entries, char *end)
{
	char	*history;
	int		t;
	int		i;
	int		h;

	history = malloc((tab_slen(entries) + tablen(entries) + 1) * sizeof(char));
	t = -1;
	h = 0;
	while (entries[++t])
	{
		i = 0;
		while (entries[t][i])
		{
			if (entries[t][0] == '\0')
				history[h++] = '\n';
			else
				history[h++] = entries[t][i++];
		}
		history[h++] = '\n';
	}
	i = 0;
	while (end[i])
		history[h++] = end[i++];
	history[h] = '\0';
	return (history);
}

static int	add_n_print(char **entries, char *input, t_token *tokens, int *t)
{
	int	len;

	len = 0;
	if ((*t) == 0)
		entries[(*t)++] = ft_strdup(tokens->input);
	input = readline("heredoc> ");
	if (input && input[0] == '\0')
	{
		entries[(*t)] = ft_strdup("");
		return (1);
	}
	if (input == NULL)
		return (-42);
	len = ft_strlen(tokens->arg_operator);
	if (ft_strncmp(input, tokens->arg_operator, len) == 0)
	{
		free(input);
		return (0);
	}
	entries[(*t)] = ft_strdup(input);
	if (input)
		free(input);
	return (1);
}

static int	while_one(char **entries, char *input, t_token *tokens)
{
	int	check_error;
	int	t;

	t = 0;
	while (1)
	{
		check_error = add_n_print(entries, input, tokens, &t);
		if (check_error == -42)
			return (-42);
		if (check_error == 0)
			break ;
		t++;
	}
	return (1);
}

static void	writing_heredoc(char **entries)
{
	int	t;

	t = 1;
	while (entries[t])
	{
		write(STDOUT_FILENO, entries[t], ft_strlen(entries[t]));
		write(STDOUT_FILENO, "\n", 1);
		t++;
	}
}

// (<<)
int	redirect_input_command(t_token *tokens, t_export *alloctrack)
{
	char	*input;
	char	*join;
	char	**entries;
	int		value;

	input = NULL;
	entries = malloc(200 * sizeof(char *));
	if (!entries)
		return (error_zero(2));
	value = while_one(entries, input, tokens);
	if (value == -42)
		return (value);
	if (value == -1)
		return (0);
	join = join_entries(entries, tokens->arg_operator);
	add_history(join);
	redirect_output(alloctrack->heredoc);
	writing_heredoc(entries);
	dup2(alloctrack->std[1], STDOUT_FILENO);
	free_tab(entries);
	return (1);
}

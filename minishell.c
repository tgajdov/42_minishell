/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:29:26 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 17:08:42 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* static void	header(void)
{
	printf("\033[1;32m  __  __               _          _ _\n");
	printf(" |  \\/   _ _ __  _ ___| |__   ___| | |\n");
	printf(" | |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n");
	printf(" | |  | | | | | | \\__ \\ | | |  __/ | |\n");
	printf(" |_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|\n");
	printf("  _    _ _ _   _ _ ___ _   _   ___ _ _ \033[0m\n\n");
} */

static t_token	*take_n_tokenize(t_export *alloctrack)
{
	t_token	*tokens;
	char	*input;

	input = take_input(alloctrack);
	input = input_pipe(input);
	if (!input)
		return (NULL);
	if (input && input[0] == '\0')
	{
		free(input);
		tokens = create_void_token();
		return (tokens);
	}
	tokens = parsing_input(input);
	if (!tokens)
	{
		free(input);
		return (NULL);
	}
	tokens->input = ft_strdup(input);
	free(input);
	return (tokens);
}

static int	execute(t_token **tokens, t_export *alloctrack, int fd[2])
{
	*tokens = take_n_tokenize(alloctrack);
	if (!(*tokens))
		return (0);
	if ((*tokens)->pipe == 42)
		return (-42);
	while ((*tokens))
	{
		if (check_for_next_redirect(tokens, alloctrack) == 1)
			return (1);
		if ((*tokens)->pipe == 1)
		{
			redirect_input(alloctrack->pipex);
			(*tokens) = (*tokens)->next;
		}
		if ((*tokens)->next)
			if ((*tokens)->next->pipe == 1)
				redirect_output(alloctrack->pipex);
		alloctrack->back = lexing((*tokens), alloctrack);
		if (alloctrack->back != 1)
			return (alloctrack->back);
		redirect_std(fd);
		(*tokens) = (*tokens)->next;
	}
	return (alloctrack->status);
}

static int	minishell(t_export *alloctrack, int fd[2])
{
	t_token				*tokens;

	tokens = NULL;
	while (1)
	{
		setup_signal();
		alloctrack->status = execute(&tokens, alloctrack, fd);
		if (alloctrack->should_exit)
		{
			if (alloctrack->status == 255)
				printf("exit\n");
			if (alloctrack->status == 255)
				printf("mnsh: exit: %s: numeric argument required\n",
					tokens->argument[0]);
			free_token_chain(tokens);
			ft_exit(alloctrack->status, alloctrack);
		}
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_export	*alloctrack;
	int			fd[2];

	(void)argc;
	(void)argv;
	//header();
	save_std(fd);
	alloctrack = init(env);
	redirect_std(fd);
	alloctrack->std[0] = dup(0);
	alloctrack->std[1] = dup(1);
	minishell(alloctrack, fd);
	return (0);
}

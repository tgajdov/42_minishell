/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnsh_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:32 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:27:18 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_void_token(void)
{
	t_token	*token_void;

	token_void = malloc(sizeof(t_token));
	if (!token_void)
		return (NULL);
	token_void->input = ft_strdup("");
	token_void->argument = NULL;
	token_void->cmd = NULL;
	token_void->operator = NULL;
	token_void->arg_operator = NULL;
	token_void->pipe = 42;
	token_void->quotes = 0;
	token_void->next = NULL;
	return (token_void);
}

void	save_std(int fd[2])
{
	fd[0] = dup(0);
	fd[1] = dup(1);
}

void	redirect_std(int fd[2])
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

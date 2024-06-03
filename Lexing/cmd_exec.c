/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:14:03 by brferran          #+#    #+#             */
/*   Updated: 2024/05/30 13:14:53 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_directory(const char *path) 
{
	struct	stat st;

	if (stat(path, &st) == -1) 
		return (0);
	if (S_ISDIR(st.st_mode)) 
		return (1);
	return (0);
}

static int	is_executable(const char *path)
{
	struct	stat st;

	if (stat(path, &st) == -1)
		return (0);
	if ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP)
		|| (st.st_mode & S_IXOTH))
		return (1);
	return (0);
}

static int is_regular_file(const char *path) 
{
	struct	stat st;

	if (stat(path, &st) == -1) {
		return (0);
	}
	if (S_ISREG(st.st_mode)) 
		return (1);
	return (0);
}

int	make_exec(t_token *tokens, t_export *alloctrack)
{
	// int i = 0;
	if (tokens->cmd[0] == '/'
		|| (tokens->cmd[0] == '.' && tokens->cmd[1] == '/'))
	{
		if (is_directory(tokens->cmd))
		{
			printf("mnsh: %s: is a directory\n", tokens->cmd);
			alloctrack->status = 126;
			return (0);
		}
		else if (is_regular_file(tokens->cmd))
		{
			if (is_executable(tokens->cmd))
			{
				// while(tokens->argument[i] != NULL)
				// 	printf("The argument is :%s:\n", tokens->argument[i++]);
				if (!exec(tokens->cmd, tokens->argument, alloctrack->environ))
				{
					alloctrack->status = 127;
					return (0);
				}
			}
			else
			{
				printf("mnsh: %s: Permission denied\n", tokens->cmd);
				alloctrack->status = 126;
				return (0);
			}
		}
		else
		{
			printf("mnsh: %s: : No such file or directory\n", tokens->cmd);
			alloctrack->status = 127;
			return (0);
		}
		alloctrack->status = 0;
	}
	return (1);
}

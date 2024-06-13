/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:44 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:42:32 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_argv(char **arg, char *exec)
{
	char	**fake_argv;
	int		i;
	int		j;

	i = 0;
	while (arg[i])
		i++;
	fake_argv = malloc(sizeof(char *) * (i + 2));
	if (!fake_argv)
		return (NULL);
	i = 1;
	fake_argv[0] = strdup(exec);
	j = 0;
	while (arg[j])
		fake_argv[i++] = strdup(arg[j++]);
	fake_argv[i] = NULL;
	return (fake_argv);
}

void	exec_child(char *exec, char **arg, char **fake_argv, char **env)
{
	printf("-- PROGRAM STARTED --\n");
	if (fake_argv == NULL)
	{
		if (execve(exec, arg, env) == -1)
			err_exit(1);
	}
	else
	{
		if (execve(exec, fake_argv, env) == -1)
		{
			free_tab(fake_argv);
			err_exit(1);
		}
		free_tab(fake_argv);
	}
}

int	exec(char *exec, char **arg, char **env, t_export *alloctrack)
{
	pid_t	children;
	char	**fake_argv;

	fake_argv = NULL;
	if (arg[0] != NULL)
		fake_argv = get_argv(arg, exec);
	children = fork();
	if (children == -1)
		return (error_zero(10));
	signal(SIGINT, SIG_IGN);
	if (children == 0)
	{
		exec_child(exec, arg, fake_argv, env);
	}
	waitpid(children, &alloctrack->status, 0);
	if (WIFEXITED(alloctrack->status))
		alloctrack->status = WEXITSTATUS(alloctrack->status);
	else if (WIFSIGNALED(alloctrack->status))
		alloctrack->status = WTERMSIG(alloctrack->status) + 128;
	else
		alloctrack->status = 1;
	printf("-- PROGRAM EXIT --\n");
	return (1);
}

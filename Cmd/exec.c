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

int	exec(char *exec, char **arg, char **env)
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
		printf("-- PROGRAM STARTED --\n");
		if (fake_argv == NULL)
		{
			if (execve(exec, arg, env) == -1)
				return (err_exit(1));
		}
		else
		{
			if (execve(exec, fake_argv, env) == -1)
			{
				free_tab(fake_argv);
				return (err_exit(1));
			}
			free_tab(fake_argv);
		}
	}
	wait(NULL);
	printf("-- PROGRAM EXIT --\n");
	return (1);
}

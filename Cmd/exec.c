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

int	exec(char *exec, char **arg, char **env)
{
	pid_t	children;

	children = fork();
	if (children == -1)
		return (error_zero(10));
	signal(SIGINT, SIG_IGN);
	if (children == 0)
	{
		printf("-- PROGRAM STRATED --\n");
		if (execve(exec, arg, env) == -1)
			return (err_exit(1));
	}
	wait(NULL);
	printf("-- PROGRAM EXIT --\n");
	return (1);
}

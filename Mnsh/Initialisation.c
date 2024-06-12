/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:24 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:23:30 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_tabdup(char **env)
{
	int		t;
	char	**dup;

	dup = malloc((tablen(env) + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	t = 0;
	while (env[t])
	{
		dup[t] = ft_strdup(env[t]);
		t++;
	}
	dup[t] = NULL;
	return (dup);
}

t_export	*init(char **env)
{
	t_export	*alloctrack;
	char		*reg;

	reg = "Register.\n";
	alloctrack = malloc(sizeof(t_export));
	if (!alloctrack)
		return (NULL);
	alloctrack->environ = ft_tabdup(env);
	if (!alloctrack->environ)
		return (NULL);
	alloctrack->export_env = malloc(sizeof(char *));
	if (!alloctrack->export_env)
		return (NULL);
	alloctrack->status = 0;
	alloctrack->should_exit = 0;
	alloctrack->way = NULL;
	alloctrack->heredoc = HRDC_FILE;
	redirect_output(alloctrack->heredoc);
	write(STDOUT_FILENO, reg, ft_strlen(reg));
	alloctrack->pipex = PIPE_FILE;
	redirect_output(alloctrack->pipex);
	write(STDOUT_FILENO, reg, ft_strlen(reg));
	alloctrack->back = 42;
	alloctrack->access = 42;
	return (alloctrack);
}

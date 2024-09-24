/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:59 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 18:41:44 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(t_token *tokens)
{
	if (!tokens->cmd)
		return (1);
	if (ft_strcasecmp(tokens->cmd, "echo", 4) == 0
		|| ft_strcasecmp(tokens->cmd, "cd", 2) == 0
		|| ft_strcasecmp(tokens->cmd, "env", 3) == 0
		|| ft_strcasecmp(tokens->cmd, "unset", 5) == 0
		|| ft_strcasecmp(tokens->cmd, "export", 6) == 0
		|| ft_strcasecmp(tokens->cmd, "pwd", 3) == 0
		|| ft_strcasecmp(tokens->cmd, "exit", 4) == 0
		|| (tokens->cmd[0] == '.' && tokens->cmd[1] == '/')
		|| tokens->cmd[0] == '$')
		return (1);
	else
		return (0);
}

static char	**add_cmd(char *cmd, char **way)
{
	char	**new_way;
	char	*tmp;
	int		t;

	t = 0;
	new_way = malloc((tablen(way) + 1) * sizeof(char *));
	if (!new_way)
		return (NULL);
	while (way[t])
	{
		tmp = malloc((ft_strlen(way[t]) + ft_strlen(cmd) + 1) * sizeof(char));
		if (!tmp)
			return (NULL);
		complete_way(way, cmd, &tmp, t);
		new_way[t] = ft_strdup(tmp);
		free(tmp);
		t++;
	}
	new_way[t] = NULL;
	return (new_way);
}

static int	exec_sys_child(t_token *tokens, t_export *alloctrack, char **way)
{
	pid_t	child;

	if (tokens->operator)
		if (ft_strncmp(tokens->operator, "<<", 2) == 0
			&& tokens->operator[2] == '\0')
			redirect_input(alloctrack->heredoc);
	default_signals();
	child = fork();
	if (child == -1)
		exit(0);
	if (child == 0)
	{
		tokens->argument = argument_system(tokens);
		execve(way[alloctrack->access], tokens->argument,
			alloctrack->environ);
		(ft_putendl_fd(strerror(errno), 2), exit(127));
	}
	waitpid(child, &alloctrack->status, 0);
	if (WIFEXITED(alloctrack->status))
		alloctrack->status = WEXITSTATUS(alloctrack->status);
	else if (WIFSIGNALED(alloctrack->status))
		alloctrack->status = WTERMSIG(alloctrack->status) + 128;
	else
		alloctrack->status = 1;
	return (0);
}

int	exec_system(t_token *tokens, t_export *alloctrack)
{
	char	**way;

	way = NULL;
	if (is_builtin(tokens))
		return (1);
	alloctrack->way = init_way_path(alloctrack);
	if (!alloctrack->way)
		return (1);
	if (check_if_good_way(alloctrack->way, tokens->cmd) != NULL)
		way = check_if_good_way(alloctrack->way, tokens->cmd);
	else
		way = add_cmd(tokens->cmd, alloctrack->way);
	signal(SIGINT, SIG_IGN);
	if (is_access(way, alloctrack))
		return (exec_sys_child(tokens, alloctrack, way));
	return (1);
}

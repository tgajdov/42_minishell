/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:55 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 16:59:22 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_access(char **way, t_export *alloctrack)
{
	int	t;

	t = 0;
	while (way[t])
	{
		if (access(way[t], X_OK) == 0)
		{
			alloctrack->access = t;
			return (1);
		}
		t++;
	}
	return (0);
}

char	**argument_system(t_token *tokens)
{
	char	**arg_sys;
	int		i;
	int		t;

	arg_sys = malloc((tablen(tokens->argument) + 2) * sizeof(char *));
	if (!arg_sys)
		return (NULL);
	i = 0;
	arg_sys[i++] = ft_strdup(tokens->cmd);
	t = 0;
	while (tokens->argument[t])
		arg_sys[i++] = ft_strdup(tokens->argument[t++]);
	arg_sys[i] = NULL;
	return (arg_sys);
}

static char	*take_path(char **env)
{
	char	*tmp;
	int		t;

	t = 0;
	tmp = NULL;
	while (env[t])
	{
		if (env[t][0] == 'P' && env[t][1] == 'A' && env[t][2] == 'T'
			&& env[t][3] == 'H' && env[t][4] == '=')
			tmp = ft_strdup(env[t]);
		t++;
	}
	if (!tmp)
		return (NULL);
	tmp = ft_strchr(tmp, '=');
	tmp = tmp + 1;
	return (tmp);
}

static char	**put_slash(char **way)
{
	char	*tmp;
	int		t;
	int		i;

	t = 0;
	while (way[t])
	{
		i = -1;
		tmp = malloc((ft_strlen(way[t]) + 2) * sizeof(char *));
		if (!tmp)
			return (NULL);
		while (way[t][++i])
			tmp[i] = way[t][i];
		tmp[i++] = '/';
		tmp[i] = '\0';
		if (way[t])
			free(way[t]);
		way[t] = ft_strdup(tmp);
		if (tmp)
			free(tmp);
		t++;
	}
	return (way);
}

char	**init_way_path(t_export *alloctrack)
{
	char	*path;

	path = take_path(alloctrack->environ);
	if (!path)
		return (NULL);
	alloctrack->way = ft_split(path, ':');
	if (!alloctrack->way)
		return (NULL);
	alloctrack->way = put_slash(alloctrack->way);
	return (alloctrack->way);
}

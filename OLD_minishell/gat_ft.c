/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gat_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:13:44 by tgajdov           #+#    #+#             */
/*   Updated: 2024/06/13 12:13:46 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(t_export *allotrack, char *var)
{
	int	i;

	i = 0;
	while (ft_strnstr(allotrack->environ[i], var, ft_strlen(var)) == 0)
		i++;
	if (ft_strnstr(allotrack->environ[i], var, ft_strlen(var)) != 0)
		return (allotrack->environ[i] + ft_strlen(var) + 1);
	else
		return (0);
}

/* char	*ft_getcmdpath(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*inter_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		inter_path = ft_strjoin(paths[i++], "/");
		path = ft_strjoin(inter_path, cmd);
		free(inter_path);
		if ((access(path, F_OK)) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	ft_exceve(char *av, char **envp)
{
	char	*thepath;

	thepath = ft_getcmdpath(av, envp);
	if (execve(thepath, &av, envp) == -1)
	{
		perror("Couldn't exit");
		exit(1);
	}
} */

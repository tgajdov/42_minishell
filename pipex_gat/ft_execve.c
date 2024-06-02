/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:28:04 by tgajdov           #+#    #+#             */
/*   Updated: 2024/02/19 18:28:06 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getcmdpath(char *cmd, char **envp)
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

void	ft_exceve(int ac, char **av, char **envp)
{
	char	*thepath;
	char	**thecmd;

	thecmd = ft_split(av[ac], ' ');
	thepath = ft_getcmdpath(thecmd[0], envp);
	if (execve(thepath, thecmd, envp) == -1)
		ft_exit("Could not find programm to execute");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:05:08 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 18:14:36 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_getcmdpath(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*inter_path;

	i = 0;
	DEBUG("je suis dans getcmdpath");
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
	DEBUG("je suis dans ft_execve");
	thepath = ft_getcmdpath(thecmd[0], envp);
	if (execve(thepath, thecmd, envp) == -1)
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 2)
		ft_exceve(ac, av, envp);
	else
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	return (0);
}
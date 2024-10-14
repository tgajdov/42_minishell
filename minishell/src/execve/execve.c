/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:05:08 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/14 15:12:00 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	*ft_getcmdpath(char *cmd, char **envp)
{
	int		i;
	char	*good_path;
	char	**path_possibilities;
	char	*inter_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_possibilities = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_possibilities[i])
	{
		inter_path = ft_strjoin(path_possibilities[i++], "/");
		good_path = ft_strjoin(inter_path, cmd);
		free(inter_path);
		if ((access(good_path, F_OK)) == 0)
			return (good_path);
		free(good_path);
	}
	i = -1;
	while (path_possibilities[++i])
		free(path_possibilities[i]);
	free(path_possibilities);
	return (0);
}

void	ft_exceve(char *cmd_str, char **envp)
{
	char	*cmd_path;
	char	**cmd_tab;

	cmd_tab = ft_split(cmd_str, ' ');
	// Comment free cmd_tab?
	
	//faut-il securiser du genre
	// if(!cmd_tab)
	// 	return();
	cmd_path = ft_getcmdpath(cmd_tab[0], envp);
	if (execve(cmd_path, cmd_tab, envp) == -1)
	{
		free(cmd_path);
		ft_free_tab(cmd_tab);
		printf("execve failed\n");
		return (1);
	}
}

/**
 * @brief Ft_exceve execute une commande en trouvant le chemin de la commande
 * dans les variables d'environnement.
 *
 * @param cmd_str La commande a executer AVEC ses arguments.
 * @param envp Le tableau des variables d'environnement.
 *
 * La fonction split la commande en un tableau de mots pour recupere le nom de
 * la commande. Ensuite, elle utilise la fonction ft_getcmdpath pour trouver le
 * chemin de la commande dans les variables d'environnement. Enfin, elle
 * execute la commande avec execve.
 *
 * Si la commande echoue, la fonction affiche un message d'erreur et quitte le
 * programme.
 */

/* int	main(int ac, char **av, char **envp)
{
	// char *argv = {"cd /home/tgajdov/Desktop"};
	char *argv = {"clear"};

	if (ac && av)
		ft_exceve(argv, envp);
	else
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:28:13 by tgajdov           #+#    #+#             */
/*   Updated: 2024/02/19 18:28:16 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *str)
{
	perror(str);
	exit(1);
}

//fd[0] - read
//fd[1] - write
//ft_exceve(2, av, envp); //2 est ici le num de l'arg a executé

void	ft_child_process(int *fd, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_exit("Couldn't open infile");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_exceve(2, av, envp);
}

void	ft_parent_process(int *fd, char **av, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_exit("Couldn't open outfile");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_exceve(3, av, envp);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	ft_check_entry(ac, av);
	if (pipe(fd) == -1)
		ft_exit("Couldn't create the pipe");
	pid = fork();
	if (pid == -1)
		ft_exit("Couldn't create the fork");
	if (pid == 0)
		ft_child_process(fd, av, envp);
	wait(NULL);
	ft_parent_process(fd, av, envp);
	return (0);
}

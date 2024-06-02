/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:27:54 by tgajdov           #+#    #+#             */
/*   Updated: 2024/02/19 18:27:55 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getpwd(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PWD", 3) == 0)
		i++;
	return (envp[i] + 4);
}

void	ft_check_ac(int ac)
{
	if (ac != 5)
		ft_exit("strcture <file1 cmd1 cmd2 file2>");
}

void	ft_check_read_file(char *file)
{
	if (access(file, F_OK) != 0)
		ft_exit("Can't read a file");
}

/* void	ft_check_write_file(char *file)
{
	if (access(file, W_OK) != 0)
	{
		if (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644) == -1)
			ft_exit("File was not opened");
		printf("New file <%s> was created and oppened\n", file);
	}
} */

int	ft_check_entry(int ac, char **av)
{
	ft_check_ac(ac);
	ft_check_read_file(av[1]);
	return (1);
}

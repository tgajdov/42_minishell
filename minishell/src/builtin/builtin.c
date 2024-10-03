/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:09:17 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 17:52:04 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

/* int	builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")))
		{
			printf("%s\n", strerror(errno));
			return (1);
		}
	}
	else if (chdir(args[1]) != 0)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	return (0);
}


int builtin_env(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}


int builtin_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		i++;
	}
	printf("\n");
	return (0);
} */

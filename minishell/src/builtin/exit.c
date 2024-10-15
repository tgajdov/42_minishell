/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:09:44 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 15:47:33 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	is_numeric(const char *str)
{
	int i = 0;
	// if (str[i] == '-' || str[i] == '+')
	// 	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(char **args)
{
	int exit_code;

	ft_putstr_fd("exit\n", STDOUT_FILENO);

	if (args[1] == NULL)
		exit(0);
	if (!is_numeric(args[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		exit(2);
	}
	if (args[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		return;
	}
	exit_code = ft_atoi(args[1]);
	exit(exit_code);
}
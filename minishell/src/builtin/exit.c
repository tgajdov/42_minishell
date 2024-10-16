/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:09:44 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 15:34:42 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	builtin_exit(char **args)
{
	int exit_s;

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (args[1] == NULL)
	{
		ft_clean_ms();
		exit(0);
	}
	if (!is_numeric(args[1]))
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		ft_clean_ms();
		exit(255);
	}
	if (args[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		return;
	}
	exit_s = ft_atoi(args[1]);
	ft_clean_ms();
	exit(exit_s);
}


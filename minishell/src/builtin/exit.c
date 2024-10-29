/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:09:44 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 13:00:12 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Checks if the given string is a numeric string.
 * @param str String to check.
 * @return true if string is numeric, false otherwise.
 */
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

/**
 * @brief Handles the exit command
 * @details Prints "exit" and then exits the program with the given code.
 * If no argument is given, the default exit code is 0.
 * If the argument is not numeric, it prints an error message and exits with
 * code 255.
 * If too many arguments are given, it prints an error message and does not exit.
 * @param args The arguments given to the exit command.
 */
void	builtin_exit(char **args)
{
	int	exit_s;

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
		return ;
	}
	exit_s = ft_atoi(args[1]);
	ft_clean_ms();
	exit(exit_s);
}

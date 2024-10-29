/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:10:35 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if a given command is a built-in shell command.
 *
 * This function compares the provided argument against a list of known
 * built-in shell commands. If the argument matches any of the built-in
 * commands such as "echo", "cd", "exit", "pwd", "export", "unset", or
 * "env", the function returns true. Otherwise, it returns false.
 *
 * @param arg The command to be checked.
 * @return true if the command is a built-in, false otherwise.
 */
bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}

/**
 * @brief Execute a built-in command.
 *
 * This function takes an array of strings as arguments, where the first
 * element is the name of the command to be executed. It checks if the
 * command is a built-in shell command and executes the corresponding
 * function. If the command is not a built-in, it prints an error message
 * and returns ENO_GENERAL.
 *
 * @param args The array of strings containing the command and its arguments.
 * @return 0 if the command was executed successfully, ENO_GENERAL otherwise.
 */
int	ft_exec_builtin(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args[1]));
	if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env());
	if (ft_strcmp(args[0], "pwd") == 0)
		return (builtin_pwd());
	if (ft_strcmp(args[0], "export") == 0)
		return (builtin_export(args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (builtin_unset(args));
	if (ft_strcmp(args[0], "exit") == 0)
		builtin_exit(args);
	printf("minishell: %s: command not found\n", args[0]);
	return (ENO_GENERAL);
}

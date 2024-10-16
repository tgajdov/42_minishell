/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:41:24 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int		ft_exec_builtin(char **args)
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


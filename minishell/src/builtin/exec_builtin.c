/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 12:25:06 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

/* t_command builtin_cmds[] = {

	{"cd", &builtin_cd},
	{"env", &builtin_env},
	{"echo", &builtin_echo},
	{"export", &builtin_export},
	{"exit", &builtin_exit},
	{"pwd", &builtin_pwd},
	{"unset", &builtin_unset},
	{NULL, NULL}
} ; */

/* int	execute_builtin(char **args)
{
	t_command	*builtin_cmds;
	int			i;

	i = 0;
	if (args[0] == NULL)
		return (0);
	while (builtin_cmds[i].name)
	{
		if (ft_strncmp(args[0], builtin_cmds[i].name, 0) == 0)
		{
			builtin_cmds[i].func(args);
			return (0);
		}
		i++;
	}
	return (0);
} */


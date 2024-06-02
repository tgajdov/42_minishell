/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:14 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 16:57:08 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_echo(char *cmd, t_export *alloctrack)
{
	if (ft_strcasecmp(cmd, "echo", 4) == 0 && cmd[4] != '\0')
	{
		if (ft_strncmp(cmd, "echo -n", 7) == 0 && cmd[7] == '\0')
			return (1);
		else
		{
			printf("mnsh : %s: command not found\n", cmd);
			alloctrack->status = 127;
			return (0);
		}
	}
	return (1);
}

int	error_cd(char *cmd, t_export *alloctrack)
{
	if (ft_strcasecmp(cmd, "cd", 2) == 0 && cmd[2] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	return (1);
}

int	error_pwd(char *cmd, t_export *alloctrack)
{
	if (ft_strcasecmp(cmd, "pwd", 3) == 0 && cmd[3] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	return (1);
}

int	error_export_unset_env(char *cmd, t_export *alloctrack)
{
	if (ft_strcasecmp(cmd, "export", 6) == 0 && cmd[6] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	if (ft_strcasecmp(cmd, "unset", 5) == 0 && cmd[5] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	if (ft_strcasecmp(cmd, "env", 3) == 0 && cmd[3] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	return (1);
}

int	error_exit(char *cmd, t_export *alloctrack)
{
	if (ft_strcasecmp(cmd, "exit", 4) == 0 && cmd[4] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	return (1);
}

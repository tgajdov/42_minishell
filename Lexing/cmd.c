/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:08 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 16:56:30 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	make_unset(t_token *tokens, t_export *alloctrack)
{
	int	t;

	if (ft_strcasecmp(tokens->cmd, "unset", 5) == 0
		&& tokens->cmd[5] == '\0')
	{
		if (!tokens->argument[0])
		{
			printf("mnsh : unset : Not enough arguments\n");
			alloctrack->status = 1;
			return (0);
		}
		t = 0;
		while (tokens->argument[t])
		{
			if (!ft_unset(tokens->argument[t], alloctrack))
			{
				alloctrack->status = -42;
				return (0);
			}
			t++;
		}
		alloctrack->status = 0;
	}
	return (1);
}

static int	make_env(t_token *tokens, t_export *alloctrack)
{
	if (ft_strcasecmp(tokens->cmd, "env", 3) == 0
		&& tokens->cmd[3] == '\0')
	{
		if (tokens->argument[0] != NULL)
		{
			printf("mnsh : env -> ");
			printf("%s : No such file or directory\n", tokens->argument[0]);
			alloctrack->status = 127;
			return (1);
		}
		if (!ft_env(alloctrack))
		{
			alloctrack->status = -42;
			return (0);
		}
		alloctrack->status = 0;
	}
	return (1);
}

static int	ft_isnumb(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	make_exit(t_token *tokens, t_export *alloctrack)
{
	if (ft_strcasecmp(tokens->cmd, "exit", 4) == 0
		&& tokens->cmd[4] == '\0')
	{
		if (!(tokens->argument[0]) || (ft_isnumb(tokens->argument[0])
			&& (!(tokens->argument[1]))))
		{
			alloctrack->status = 0;
			return (-42);
		}
		else if (ft_isnumb(tokens->argument[0]) && (tokens->argument[1]))
		{
			alloctrack->status = 1;
			printf("exit: too many arguments\n");
			return (1);
		}
		else
		{
			alloctrack->status = 0;
			printf("exit: %s: numeric argument required\n", tokens->argument[0]);
			return (-42);
		}
	}
	return (1);
}

int	cmd(t_token *tokens, t_export *alloctrack)
{
	if (!tokens->cmd)
		return (1);
	if (!make_echo(tokens, alloctrack))
		return (0);
	if (!make_echon(tokens, alloctrack))
		return (0);
	if (!make_cd(tokens, alloctrack))
		return (0);
	if (!make_pwd(tokens, alloctrack))
		return (0);
	if (!make_export(tokens, alloctrack))
		return (0);
	if (!make_unset(tokens, alloctrack))
		return (0);
	if (!make_env(tokens, alloctrack))
		return (0);
	if (make_exit(tokens, alloctrack) == -42)
		return (-42);
	if (!make_exec(tokens, alloctrack))
		return (0);
	return (1);
}

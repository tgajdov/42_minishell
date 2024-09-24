/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:03 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 16:55:53 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_echo_nl(t_export *alloctrack)
{
	write (STDOUT_FILENO, "\n", 1);
	alloctrack->status = 0;
}

int	make_echo(t_token *tokens, t_export *alloctrack)
{
	int	t;

	if (ft_strcasecmp(tokens->cmd, "echo", 4) == 0
		&& tokens->cmd[4] == '\0')
	{
		t = 0;
		if (!(tokens->argument[0]))
		{
			make_echo_nl(alloctrack);
			return (0);
		}
		while (tokens->argument[t] != NULL)
		{
			if (t > 0)
				write (STDOUT_FILENO, " ", 1);
			if (!echo(tokens->argument[t++]))
			{
				alloctrack->status = 127;
				return (0);
			}
		}
		make_echo_nl(alloctrack);
	}
	return (1);
}

int	make_echon(t_token *tokens, t_export *alloctrack)
{
	int	t;

	if (ft_strncmp(tokens->cmd, "echo -n", 7) == 0
		&& tokens->cmd[7] == '\0')
	{
		t = 0;
		if (!(tokens->argument[0]))
		{
			alloctrack->status = 0;
			return (0);
		}
		while (tokens->argument[t] != NULL)
		{
			if (!echon(tokens->argument[t]))
			{
				alloctrack->status = 127;
				return (0);
			}
			t++;
		}
		alloctrack->status = 0;
	}
	return (1);
}

int	make_cd(t_token *tokens, t_export *alloctrack)
{
	if (ft_strcasecmp(tokens->cmd, "cd", 2) == 0
		&& tokens->cmd[2] == '\0')
	{
		if ((!tokens->argument[0]) || (ft_strncmp(tokens->argument[0], "~", 1)
				== 0))
			cd(get_var(alloctrack, "ZDOTDIR"), alloctrack);
		else if (ft_strncmp(tokens->argument[0], "-", 1) == 0)
			cd (get_var(alloctrack, "OLDPWD"), alloctrack);
		else if (!cd(tokens->argument[0], alloctrack))
		{
			alloctrack->status = 1;
			return (0);
		}
		alloctrack->status = 0;
	}
	return (1);
}

int	make_pwd(t_token *tokens, t_export *alloctrack)
{
	if (ft_strcasecmp(tokens->cmd, "pwd", 3) == 0
		&& tokens->cmd[3] == '\0')
	{
		if (!pwd())
		{
			alloctrack->status = -42;
			return (0);
		}
		alloctrack->status = 0;
	}
	return (1);
}

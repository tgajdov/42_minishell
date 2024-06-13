/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:39:07 by tgajdov           #+#    #+#             */
/*   Updated: 2024/06/13 11:39:09 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_unset(t_token *tokens, t_export *alloctrack)
{
	int	t;

	if (ft_strcasecmp(tokens->cmd, "unset", 5) == 0
		&& tokens->cmd[5] == '\0')
	{
		if (!tokens->argument[0])
		{
			alloctrack->status = 0;
			return (1);
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

int	make_export(t_token *tokens, t_export *alloctrack)
{
	int	t;

	if (ft_strcasecmp(tokens->cmd, "export", 6) == 0 && tokens->cmd[6] == '\0')
	{
		if (!tokens->argument[0])
		{
			if (!ft_env(alloctrack, 21))
			{
				alloctrack->status = -42;
				return (0);
			}
		}
		t = 0;
		while (tokens->argument[t] != NULL)
		{
			if (!ft_export(tokens->argument[t], alloctrack))
			{
				alloctrack->status = 1;
				return (0);
			}
			t++;
		}
	}
	alloctrack->status = 0;
	return (1);
}

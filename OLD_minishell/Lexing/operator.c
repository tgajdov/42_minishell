/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:27 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 15:36:18 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parsing_argop(t_token *tokens, t_export *alloctrack)
{
	char	**tmp;

	tmp = malloc(2 * sizeof(char *));
	if (!tmp)
		return (error_zero(2));
	tmp[0] = ft_strdup(tokens->arg_operator);
	tmp[1] = NULL;
	free(tokens->arg_operator);
	tmp = ft_parsing(tmp, alloctrack);
	if (tmp[0] && tmp[0][0] != '\0')
		tokens->arg_operator = ft_strdup(tmp[0]);
	else
		tokens->arg_operator = NULL;
	free_tab(tmp);
	return (1);
}

static int	traduct(t_token *tokens, t_export *alloctrack)
{
	if (ft_strncmp(tokens->arg_operator, "<", 1) == 0)
	{
		if (ft_strncmp(tokens->arg_operator, "<<", 2) == 0)
			printf("mnsh: parse error near '<<'\n");
		else
			printf("mnsh : parse error near '<'\n");
		alloctrack->status = 1;
		return (0);
	}
	if (ft_strncmp(tokens->arg_operator, ">", 1) == 0)
	{
		if (ft_strncmp(tokens->arg_operator, ">>", 2) == 0)
			printf("mnsh: parse error near '>>'\n");
		else
			printf("mnsh : parse error near '>'\n");
		alloctrack->status = 1;
		return (0);
	}
	parsing_argop(tokens, alloctrack);
	return (1);
}

static int	single_operator(t_token *tokens, t_export *alloctrack)
{
	if (ft_strncmp(tokens->operator, "<", 1) == 0
		&& tokens->operator[1] == '\0')
	{
		if (!redirect_input(tokens->arg_operator))
		{
			alloctrack->status = 1;
			return (0);
		}
		alloctrack->status = 0;
		return (1);
	}
	if (ft_strncmp(tokens->operator, ">", 1) == 0
		&& tokens->operator[1] == '\0')
	{
		if (!redirect_output(tokens->arg_operator))
		{
			alloctrack->status = 1;
			return (0);
		}
		alloctrack->status = 0;
		return (1);
	}
	return (1);
}

static int	double_operator(t_token *tokens, t_export *alloctrack, int compt)
{
	if (ft_strncmp(tokens->operator, ">>", 2) == 0
		&& tokens->operator[2] == '\0')
	{
		if (!redirect_stdout_append(tokens->arg_operator))
		{
			alloctrack->status = 1;
			return (0);
		}
		alloctrack->status = 0;
	}
	if (ft_strncmp(tokens->operator, "<<", 2) == 0
		&& tokens->operator[2] == '\0')
	{
		compt = redirect_input_command(tokens, alloctrack);
		if (compt == 0)
		{
			alloctrack->status = 1;
			return (0);
		}
		if (compt == -42)
			return (-42);
		alloctrack->status = 0;
	}
	return (1);
}

int	operators(t_token *tokens, t_export *alloctrack)
{
	int	back;
	int	compt;

	compt = 0;
	if (!tokens->operator)
		return (1);
	if (tokens->operator && !tokens->arg_operator)
	{
		printf("mnsh : parse error near `\\n'\n");
		return (0);
	}
	if (!traduct(tokens, alloctrack))
		return (0);
	if (!single_operator(tokens, alloctrack))
		return (0);
	back = double_operator(tokens, alloctrack, compt);
	if (back == 0)
		return (0);
	if (back == -42)
		return (-42);
	return (1);
}

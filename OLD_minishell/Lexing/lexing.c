/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:23 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 15:36:08 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexing(t_token *tokens, t_export *alloctrack)
{
	int	back;

	back = operators(tokens, alloctrack);
	if (back == 0)
		return (0);
	if (back == -42)
		return (-42);
	tokens->argument = ft_parsing(tokens->argument, alloctrack);
	if (exec_system(tokens, alloctrack))
	{
		if (!command_not_found(tokens, alloctrack))
			return (0);
		back = cmd(tokens, alloctrack);
		if (back != 1)
			return (back);
	}
	return (1);
}

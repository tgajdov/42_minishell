/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengelba <dengelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:04:03 by dengelba          #+#    #+#             */
/*   Updated: 2024/10/24 15:04:03 by dengelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/struct.h"

int	loop(t_minishell *minishell)
{
	char	*tmp;

	minishell->args = readline(PROMPT);
	tmp = ft_strtrim(minishell->args, " ");
	free(minishell->args);
	minishell->args = tmp;
	if (!minishell->args)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!count_quotes(minishell->args))
		return (ft_error(2, minishell));
	if (!lexer(minishell))
		return (ft_error(1, minishell));
	parser(minishell);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengelba <dengelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:03:55 by dengelba          #+#    #+#             */
/*   Updated: 2024/10/24 15:03:55 by dengelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/struct.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

int	add_node(char *str, t_token_type token, t_token **lexer_list)
{
	t_token	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}

int	read_words(int i, char *str, t_token **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int	token_reader(t_minishell *minishell)
{
	int		i;
	int		j;

	i = 0;
	while (minishell->args[i])
	{
		j = 0;
		i += skip_spaces(minishell->args, i);
		if (check_token(minishell->args[i]))
			j = handle_token(minishell->args, i, &minishell->lexer_list);
		else
			j = read_words(i, minishell->args, &minishell->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}

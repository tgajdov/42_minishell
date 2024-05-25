/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:13 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 16:28:42 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	yesquotes(char *arg)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (arg[i])
	{
		if (arg[i] == 39 || arg[i] == '"')
			quotes++;
		i++;
	}
	return (quotes);
}

static char	**alloc_tab(char *arg)
{
	int		i;
	int		quotes;
	char	**arg_more;

	i = -1;
	quotes = yesquotes(arg) + 2;
	arg_more = malloc(quotes * sizeof(char *));
	if (!arg_more)
	{
		perror("mnsh : Allocated memory failed");
		return (NULL);
	}
	i = 0;
	while (i < quotes)
		arg_more[i++] = NULL;
	return (arg_more);
}

static int	quote_increment(char *tmp)
{
	int	i;

	i = 0;
	if (tmp[i] == 39 || tmp[i] == '"')
		i++;
	if (tmp[0] == 39)
		while (tmp[i] != 39)
			i++;
	else if (tmp[0] == '"')
		while (tmp[i] != '"')
			i++;
	else
	{
		while ((tmp[i] != 39 || tmp[i] != '"') && tmp[i] != '\0')
			i++;
	}
	if ((tmp[i] == 39 || tmp[i] == '"') && (tmp[0] == 39 || tmp[0] == '"'))
		i++;
	return (i);
}

char	**quote_parse(char *arg)
{
	char	**arg_more;
	char	*tmp;
	int		i;
	int		t;

	arg_more = alloc_tab(arg);
	tmp = ft_strdup(arg);
	if (!tmp)
		return (NULL);
	i = 0;
	t = 0;
	while (tmp[i])
	{
		i = quote_increment(tmp);
		if (i > 0 && tmp[i] != '\0')
			arg_more[t++] = ft_substr(tmp, 0, i);
		if (i > 0 && tmp[i] == '\0')
			arg_more[t++] = ft_substr(tmp, 0, i);
		if (tmp[i] == '\0')
			break ;
		else
			tmp = tmp + i;
		i = 0;
	}
	return (arg_more);
}

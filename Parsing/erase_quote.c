/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:09 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 16:26:17 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	erase_squote(char **erase, int *i)
{
	int	mem;

	mem = (*i);
	while ((*erase)[(*i)])
	{
		(*erase)[(*i)] = (*erase)[(*i) + 1];
		(*i)++;
	}
	(*i) = mem;
	while ((*erase)[(*i)] != 39)
		(*i)++;
	mem = (*i);
	while ((*erase)[(*i)])
	{
		(*erase)[(*i)] = (*erase)[(*i) + 1];
		(*i)++;
	}
	(*i) = mem;
}

static void	erase_dquote(char **erase, int *i)
{
	int	mem;

	mem = (*i);
	while ((*erase)[(*i)])
	{
		(*erase)[(*i)] = (*erase)[(*i) + 1];
		(*i)++;
	}
	(*i) = mem;
	while ((*erase)[(*i)] != '"')
		(*i)++;
	mem = (*i);
	while ((*erase)[(*i)])
	{
		(*erase)[(*i)] = (*erase)[(*i) + 1];
		(*i)++;
	}
	(*i) = mem;
}

char	*erase_quote(char *s)
{
	char	*erase;
	int		i;

	erase = ft_strdup(s);
	if (!erase)
		return (NULL);
	i = 0;
	while (erase[i])
	{
		if (erase[i] == 39)
			erase_squote(&erase, &i);
		if (erase[i] == '"')
			erase_dquote(&erase, &i);
		i++;
	}
	erase[i] = '\0';
	free(s);
	return (erase);
}

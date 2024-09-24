/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:16 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 17:06:23 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_new_tab(char *arg, char **new, int *m)
{
	int		i;
	char	*tmp;

	free(new[(*m)]);
	tmp = ft_strdup(arg);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		while (tmp[i] == '$')
			i++;
		while (tmp[i] != '$' && tmp[i] != '?' && tmp[i] != '\0')
			i++;
		if (tmp[i] == '?')
			i++;
		if (i > 0)
			new[(*m)++] = ft_substr(tmp, 0, i);
		tmp = tmp + i;
		i = 0;
	}
	return (new);
}

static int	check_sdollars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

static int	check_tabdollars(char **arg_more)
{
	int	i;
	int	t;
	int	dollars;

	dollars = 0;
	t = 0;
	while (arg_more[t])
	{
		if (arg_more[t][0] != 39)
		{
			i = 0;
			while (arg_more[t][i])
			{
				if (arg_more[t][i] == '$')
					dollars++;
				i++;
			}
		}
		t++;
	}
	return (dollars);
}

static char	**dollars_parse(char **arg_more)
{
	int		t;
	int		m;
	char	**new;

	m = check_tabdollars(arg_more) + tablen(arg_more) + 2;
	new = malloc(m * sizeof(char *));
	if (!new)
		return (NULL);
	t = 0;
	while (t < m)
		new[t++] = NULL;
	t = 0;
	m = 0;
	while (arg_more[t])
	{
		new[m] = ft_strdup(arg_more[t]);
		if (arg_more[t][0] != 39 && check_sdollars(arg_more[t]))
			new = make_new_tab(arg_more[t], new, &m);
		if (arg_more[t][0] == 39 || !check_sdollars(arg_more[t]))
			m++;
		t++;
	}
	free_tab(arg_more);
	new[m] = NULL;
	return (new);
}

char	**replace_argument(char **argument, t_export *alloctrack)
{
	int		t;
	int		erase;
	char	**arg_more;

	t = 0;
	while (argument[t])
	{
		arg_more = quote_parse(argument[t]);
		if (!arg_more)
			return (NULL);
		arg_more = dollars_parse(arg_more);
		free(argument[t]);
		argument[t] = convert_n_concat(arg_more, alloctrack);
		if (!argument[t])
		{
			t -= 1;
			erase = t;
			while (++t <= tablen(argument))
				argument[t] = argument[t + 1];
			t = erase;
		}
		t++;
	}
	return (argument);
}

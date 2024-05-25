/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:06 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 16:24:12 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	conv_d(char **am, t_export *alloctrack)
{
	char	*dollars;
	char	*tmp;
	char	*f;
	int		i;

	i = 0;
	while ((*am)[i] != ' ' && (*am)[i] != 39
		&& (*am)[i] != '"' && (*am)[i] != '*'
		&& (*am)[i] != '?' && (*am)[i] != '\0')
		i++;
	if ((*am)[i] == '?')
		i++;
	dollars = ft_substr((*am), 0, i);
	dollars = choose_convert(dollars, alloctrack);
	tmp = ft_substr((*am), i, ft_strlen((*am)));
	f = (*am);
	(*am) = ft_strcat(dollars, tmp);
	if (f != NULL)
		free(f);
	if (tmp != NULL)
		free(tmp);
}

static char	*convert_dollars(char *arg_m, t_export *alloctrack)
{
	char	*am;

	am = ft_strdup(arg_m);
	if (!am)
		return (NULL);
	free(arg_m);
	if (am[0] == '$' && am[1] != '\0')
		conv_d(&am, alloctrack);
	return (am);
}

static char	*concat(char **arg_more)
{
	int		t;
	int		i;
	int		j;
	int		total_len;
	char	*cc;

	total_len = tab_slen(arg_more) + 1;
	cc = malloc(total_len * sizeof(char));
	if (!cc)
		return (error_null(1));
	t = 0;
	i = 0;
	while (arg_more[t])
	{
		j = 0;
		while (arg_more[t][j])
			cc[i++] = arg_more[t][j++];
		t++;
	}
	cc[i] = '\0';
	return (cc);
}

static char	**erase_convert(char **arg_more, int *t)
{
	int	mem;

	mem = (*t);
	while (arg_more[(*t)])
	{
		arg_more[(*t)] = arg_more[(*t) + 1];
		(*t)++;
	}
	(*t) = mem - 1;
	return (arg_more);
}

char	*convert_n_concat(char **arg_more, t_export *alloctrack)
{
	int		t;
	char	*cc;

	t = 0;
	while (arg_more[t])
	{
		arg_more[t] = convert_dollars(arg_more[t], alloctrack);
		if (!arg_more[t] || (arg_more[t] && arg_more[t][0] == '\0'))
			arg_more = erase_convert(arg_more, &t);
		t++;
	}
	if (!arg_more)
		return (NULL);
	if (!arg_more[0])
	{
		free(arg_more);
		return (NULL);
	}
	cc = concat(arg_more);
	free_tab(arg_more);
	return (cc);
}

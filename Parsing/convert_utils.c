/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:03 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 15:07:52 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_double_dollars(char *dollars)
{
	int		compt;
	int		i;
	char	*joined;
	char	*pid_str;

	pid_str = get_str_pid();
	i = 0;
	joined = NULL;
	while (dollars[i] == '$')
		i++;
	compt = i;
	while (compt > 1)
	{
		compt -= 2;
		if (!joined)
			joined = ft_strdup(pid_str);
		else
			joined = ft_strcat(joined, pid_str);
	}
	if (compt == 1)
		joined = ft_strcat(joined, dollars + (i - 1));
	free (pid_str);
	return (joined);
}

static int	dollar_not_translated(int c)
{
	if (c == '}' || c == ']' || c == '%' || c == '^'
		|| c == '+' || c == '/' || c == '~')
		return (1);
	return (0);
}

char	*choose_convert(char *dollars, t_export *alloctrack)
{
	char	*d;

	if (dollars[1] == '\0')
		d = ft_strdup("$");
	else if (dollars[1] == '?')
		d = last_return(alloctrack->status);
	else if (ft_isdigit(dollars[1]) && dollars[2] != '\0')
		d = ft_substr(dollars, 2, (ft_strlen(dollars) - 2));
	else if (dollar_not_translated(dollars[1]))
		d = ft_strdup(dollars);
	else if (dollars[1] == '$')
		d = make_double_dollars(dollars);
	else
		d = dollars_lex(dollars + 1, alloctrack);
	if (d == NULL)
		d = ft_strdup("");
	free(dollars);
	return (d);
}

char	*dollars_lex(char *var_name, t_export *alloctrack)
{
	char	*value;
	int		found;
	int		t;
	int		len;

	t = 0;
	found = 0;
	len = ft_strlen(var_name);
	while (alloctrack->environ[t])
	{
		if (ft_strncmp(var_name, alloctrack->environ[t], len) == 0
			&& alloctrack->environ[t][ft_strlen(var_name)] == '=')
		{
			value = ft_strdup(strchr(alloctrack->environ[t], '='));
			found = 1;
		}
		t++;
	}
	if (found == 0)
		return (NULL);
	value = value + 1;
	return (value);
}

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;
	char	*cat;

	if (!dst && !src)
		return (NULL);
	i = ft_strlen(dst) + ft_strlen(src) + 1;
	cat = malloc(i * sizeof(char));
	if (!cat)
		return (error_null(1));
	i = 0;
	while (dst[i])
	{
		cat[i] = dst[i];
		i++;
	}
	j = 0;
	while (src[j])
		cat[i++] = src[j++];
	cat[i] = '\0';
	return (cat);
}

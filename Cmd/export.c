/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:55 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:47:46 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_realloc(char *v_env, t_export *alloctrack)
{
	char	**new_environ;
	int		i;

	i = tablen(alloctrack->environ) + 2;
	new_environ = malloc(i * sizeof(char *));
	if (!new_environ)
		return (NULL);
	i = 0;
	while (alloctrack->environ[i])
	{
		new_environ[i] = ft_strdup(alloctrack->environ[i]);
		i++;
	}
	new_environ[i++] = ft_strdup(v_env);
	new_environ[i] = NULL;
	free_tab(alloctrack->environ);
	return (new_environ);
}

static void	check_environ(char *v_env, t_export *alloctrack, int *i, int *find)
{
	char	*name;
	int		t;

	name = ft_substr(v_env, 0, (*i));
	t = 0;
	while (alloctrack->environ[t])
	{
		if ((ft_strncmp(alloctrack->environ[t], name, ft_strlen(name)) == 0)
			&& alloctrack->environ[t][ft_strlen(name)] == '=')
		{
			free(alloctrack->environ[t]);
			alloctrack->environ[t] = ft_strdup(v_env);
			(*find) = 1;
		}
		t++;
	}
}

static int	ft_check_id(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (!ft_isalpha(str[i]))
		{
			printf("mnsh: export: `%s': not a valid identifier\n", str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_export(char *v_env, t_export *alloctrack)
{
	int	i;
	int	found;

	printf("`%s'\n", v_env);
	if (!ft_check_id(v_env))
		return (0);
	i = 0;
	while (v_env[i] != '=')
		i++;
	if (v_env[i] == '\0')
		return (0);
	if (i == 0)
	{
		printf("mnsh: export: `%s': not a valid identifier\n", v_env);
		return (0);
	}
	found = 0;
	if (!alloctrack->environ[0])
		alloctrack->environ[0] = ft_strdup(v_env);
	else
	{
		check_environ(v_env, alloctrack, &i, &found);
		if (found == 0)
			alloctrack->environ = ft_realloc(v_env, alloctrack);
	}
	return (1);
}

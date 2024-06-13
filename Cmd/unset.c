/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:04 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 14:01:12 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_var_export(t_export *alloctrack, int *i)
{
	int	j;

	j = (*i);
	while (alloctrack->export_env[j])
	{
		alloctrack->export_env[j] = alloctrack->export_env[j + 1];
		j++;
	}
	(*i) -= 1;
}

static void	delete_var(t_export *alloctrack, int *i)
{
	int	j;

	j = (*i);
	while (alloctrack->environ[j])
	{
		alloctrack->environ[j] = alloctrack->environ[j + 1];
		j++;
	}
	(*i) -= 1;
}

static int	ft_check_id_unset(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && !(str[i] == '_'))
	{
		printf("mnsh: unset: `%s': not a valid identifier\n", str);
		return (0);
	}
	while (str[i] != '\0' && str[i] != '=')
	{
		if (!(str[i] == '_') && !ft_isalnum(str[i]))
		{
			printf("mnsh: unset: `%s': not a valid identifier\n", str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_unset(char *var_name, t_export *alloctrack)
{
	int	i;

	if (!alloctrack->environ[0])
		printf("mnsh : unset : non-existent environment table\n");
	if (!alloctrack->environ[0])
		return (0);
	if (!ft_check_id_unset(var_name))
		return (1);
	i = -1;
	while (alloctrack->environ[++i])
	{
		if (ft_strncmp(alloctrack->environ[i], var_name, ft_strlen(var_name))
			== 0 && alloctrack->environ[i][ft_strlen(var_name)] == '=')
			delete_var(alloctrack, &i);
	}
	i = -1;
	while (alloctrack->export_env[++i])
	{
		if (ft_strncmp(alloctrack->export_env[i], var_name,
				ft_strlen(var_name)) == 0
			&& (alloctrack->export_env[i][ft_strlen(var_name)] == '='
			|| alloctrack->export_env[i][ft_strlen(var_name)] == '\0'))
			delete_var_export(alloctrack, &i);
	}
	return (1);
}

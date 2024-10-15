/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:16:46 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 08:46:12 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	is_valid_identifier(const char *str)
{
	int i = 0;

	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	update_env(char *key_value)
{
	char **env = environ; //définir l'environnement courant
	int len = 0;
	
	while (key_value[len] && key_value[len] != '=')
		len++;
	while (*env)
	{
		if (ft_strncmp(*env, key_value, len) == 0 && (*env)[len] == '=')
		{
			free(*env);
			*env = ft_strdup(key_value);
			if (!*env)
				return (1);
			return (0);
		}
		env++;
	}
	env = ft_realloc(environ, sizeof(char *) * (ft_env_len(environ) + 2));
	if (!env)
		return (1);
	env[ft_env_len(environ)] = ft_strdup(key_value);
	env[ft_env_len(environ) + 1] = NULL;
	environ = env;
	return (0);
}

void	builtin_export(char **args)
{
	int i = 1;
	char **env = environ; //définir l'environnement courant

	if (!args[1])
	{
		while (*env)
		{
			printf("declare -x %s\n", *env);
			env++;
		}
		return;
	}
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
		{
			if (update_env(args[i]) != 0)
				printf("export: memory allocation error\n");
		}
		else
			printf("export: '%s': not a valid identifier\n", args[i]);
		i++;
	}
}
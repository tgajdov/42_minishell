/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:16:46 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 12:32:40 by tgajdov          ###   ########.fr       */
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

int	update_env(char *key_value, char **envp)
{
	int len = 0;
	
	while (key_value[len] && key_value[len] != '=')
		len++;
	while (*envp)
	{
		if (ft_strncmp(*envp, key_value, len) == 0 && (*envp)[len] == '=')
		{
			free(*envp);
			*envp = ft_strdup(key_value);
			if (!*envp)
				return (1);
			return (0);
		}
		envp++;
	}
	envp = ft_realloc(envp, sizeof(char *) * ft_env_len(envp), sizeof(char *) * (ft_env_len(envp) + 2));
	if (!envp)
		return (1);
	envp[ft_env_len(envp)] = ft_strdup(key_value);
	envp[ft_env_len(envp) + 1] = NULL;
	return (0);
}


void	builtin_export(char **args, char **envp)
{
	int i = 1;

	if (!args[1])
	{
		while (*envp)
		{
			printf("declare -x %s\n", *envp);
			envp++;
		}
		return;
	}
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
		{
			if (update_env(args[i], envp) != 0)
				printf("export: memory allocation error\n");
		}
		else
			printf("export: '%s': not a valid identifier\n", args[i]);
		i++;
	}
}
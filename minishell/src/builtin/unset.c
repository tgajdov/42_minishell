/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:17:33 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 15:48:38 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	ft_env_len(char **env)
{
	int len;
	
	len = 0;
	while (env[len])
		len++;
	return (len);
}
int	ft_unsetenv(char *key, char **envp)
{
	int		len;
	int		j;

	len = ft_strlen(key);
	j = 0;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], key, len) == 0 && envp[j][len] == '=')
		{
			free(envp[j]);
			while (envp[j])
			{
				envp[j] = envp[j + 1];
				j++;
			}
			return (0);
		}
		j++;
	}
	return (1);
}

void	builtin_unset(char **args, char **envp)
{
	int	i;
	
	i = 1;
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
		{
			if (ft_unsetenv(args[i], envp) != 0)
				printf("unset: %s: failed to unset\n", args[i]);
		}
		else
			printf("unset: '%s': not a valid identifier\n", args[i]);
		i++;
	}
}

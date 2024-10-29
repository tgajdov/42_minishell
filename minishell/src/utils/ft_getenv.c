/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:40 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:32:36 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Searches for the environment variable given by 'name' in the array given by
 * 'envp'.
 *
 * @param name The name of the environment variable to search for.
 * @param envp The array of environment variables.
 *
 * @return Returns the value of the environment variable if found, otherwise
 *         it returns NULL.
 */
char	*ft_getenv(const char *name, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

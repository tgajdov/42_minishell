/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:34:02 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 12:59:45 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Extract the key from a key value pair given as a string.
 * @param str The string to extract the key from.
 * @return The extracted key as a string.
 */
char	*ft_extract_key(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (ft_garbage_collector(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

/**
 * Extracts the value from a key-value pair given as a string.
 * Assumes that the key and value are separated by an '=' character.
 * @param str The string containing the key-value pair.
 * @return The extracted value as a string, or NULL if '=' is not found.
 */
char	*ft_extract_value(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (ft_garbage_collector(
					ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

/**
 * Initializes the envlst linked list from the environment variables.
 * The linked list is a copy of the environment variables, and is used
 * to store the current state of the environment.
 * @return None
 */
void	ft_init_envlst(void)
{
	int			i;
	char		**environ;
	char		*key;
	char		*value;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	environ = g_minishell->environ;
	if (!environ)
		return ;
	i = 0;
	while (environ[i])
	{
		key = ft_extract_key(environ[i]);
		value = ft_extract_value(environ[i]);
		ft_update_envlst(key, value, true);
		i++;
	}
}

/**
 * Prints the environment variables to the standard output.
 * The format of the output is the same as the environment variables,
 * with each key-value pair on a separate line.
 * @return 0 on success, errno otherwise.
 */
int	builtin_env(void)
{
	t_env		*list;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	list = g_minishell->envlst;
	while (list)
	{
		if (list->value != NULL)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (ENO_SUCCESS);
}

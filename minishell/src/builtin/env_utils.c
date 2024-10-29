/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:36:43 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 12:58:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if an environment variable exists.
 *
 * @param key The name of the environment variable to check.
 * @return true if the environment variable exists, false otherwise.
 */
bool	ft_env_entry_exists(char *key)
{
	t_env		*envlst;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	envlst = g_minishell->envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (true);
		envlst = envlst->next;
	}
	return (false);
}

/**
 * @brief Creates a new t_env node.
 *
 * @param key The key of the new node.
 * @param value The value of the new node,
 * or NULL if the node should not have a value.
 * @return A pointer to the new node.
 */
static t_env	*ft_envlst_new(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_garbage_collector(ft_strdup(key), false);
	if (value)
		new->value = ft_garbage_collector(ft_strdup(value), false);
	new->next = NULL;
	return (new);
}

/**
 * @brief Returns the value of a specified environment variable.
 *
 * @param key The name of the environment variable to look up.
 * @return The value of the environment variable,
 * or NULL if the variable does not exist.
 */
char	*ft_get_envlst_val(char *key)
{
	t_env		*envlst;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	envlst = g_minishell->envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

/**
 * @brief Adds a new node to the end of the linked list of environment variables.
 *
 * @param new The new node to add.
 */
void	ft_envlst_back(t_env *new)
{
	t_env		*curr;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	if (!g_minishell->envlst)
	{
		g_minishell->envlst = new;
		return ;
	}
	curr = g_minishell->envlst;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}

/**
 * @brief Updates the value of an environment variable,
 * or creates a new one if it does not exist.
 *
 * @param key The name of the environment variable to update.
 * @param value The new value of the environment variable,
 * or NULL to remove the variable.
 * @param create Whether to create a new environment variable
 * if one does not already exist.
 * @return void
 */
void	ft_update_envlst(char *key, char *value, bool create)
{
	t_env		*envlst;
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	envlst = g_minishell->envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
				envlst->value = ft_garbage_collector(ft_strdup(value), false);
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		ft_envlst_back(ft_envlst_new(key, value));
}

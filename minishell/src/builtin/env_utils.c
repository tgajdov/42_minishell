/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:36:43 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/17 07:21:56 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

char	*ft_get_envlst_val(char *key)
{
	t_env	*envlst;
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

void	ft_envlst_back(t_env *new)
{
	t_env	*curr;
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

void	ft_update_envlst(char *key, char *value, bool create)
{
	t_env	*envlst;
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

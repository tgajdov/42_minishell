/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:17:33 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:48:48 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_unset_helper(char *key)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = g_minishell.envlst;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				g_minishell.envlst = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	builtin_unset(char **args)
{
	int		i;
	bool	err;

	i = 1;
	if (!args[1])
		return (0);
	err = false;
	while (args[i])
	{
		if (!ft_check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = true;
		}
		else
			ft_unset_helper(
				ft_garbage_collector(ft_extract_key(args[i]), false));
		i++;
	}
	return (err);
}

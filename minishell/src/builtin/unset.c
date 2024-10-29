/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:17:33 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 13:28:07 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Removes an environment variable from the global environment list.
 *
 * This function searches for the specified environment variable by key
 * in the global environment list and removes it if found. If the variable
 * is not found, the list remains unchanged.
 *
 * @param key The key of the environment variable to be removed.
 */
static void	ft_unset_helper(char *key)
{
	t_minishell	*g_minishell;
	t_env		*current;
	t_env		*prev;

	g_minishell = get_g_minishell();
	prev = NULL;
	current = g_minishell->envlst;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				g_minishell->envlst = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * @brief Removes environment variables from the environment list.
 *
 * This function takes a list of arguments and attempts to unset each one
 * from the environment list. For each argument, it first checks if the 
 * argument is a valid identifier using `ft_check_key`. If the identifier
 * is invalid, it outputs an error message to standard error and sets an
 * error flag. If the identifier is valid, it calls `ft_unset_helper` to
 * remove the variable from the environment list.
 *
 * @param args A null-terminated array of strings representing the 
 * environment variable keys to be unset. The first element is expected
 * to be the command name and is ignored.
 * @return Returns 0 if all variables are successfully unset, or 1 if there
 * were any errors due to invalid identifiers.
 */
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

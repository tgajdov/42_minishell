/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:35 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 13:30:54 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Clears the linked list of environment variables.
 *
 * Iterates through the linked list of environment variables,
 * freeing each node and setting the next pointer to NULL.
 * The head of the list is then set to NULL.
 *
 * @return void
 */
static void	ft_clear_envlst(void)
{
	t_minishell	*g_minishell;
	t_env		*envlst;
	t_env		*envlst_tofree;

	g_minishell = get_g_minishell();
	envlst = g_minishell->envlst;
	while (envlst)
	{
		envlst_tofree = envlst;
		envlst = envlst->next;
		free(envlst_tofree);
	}
	g_minishell->envlst = NULL;
}

/**
 * @brief Clears all the data structures and resources used by minishell.
 *
 * Frees the AST, clears the linked list of environment variables,
 * clears the shell's history and resets the terminal settings.
 *
 * @return void
 */
void	ft_clean_ms(void)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	ft_garbage_collector(NULL, true);
	ft_clear_ast(&g_minishell->ast);
	ft_clear_envlst();
	clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell->original_term);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:35 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/28 15:27:09 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	ft_clean_ms(void)
{
	ft_garbage_collector(NULL, true);
	ft_clear_ast(&g_minishell.ast);
	ft_clear_envlst();
	clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell.original_term);
}

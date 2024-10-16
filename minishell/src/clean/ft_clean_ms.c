/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:35 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:50:11 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_clear_envlst(void)
{
	t_env	*envlst;
	t_env	*envlst_tofree;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		envlst_tofree = envlst;
		envlst = envlst->next;
		free(envlst_tofree);
	}
	g_minishell.envlst = NULL;
}

void	ft_clean_ms(void)
{
	// ft_garbage_collector(NULL, true);
	// ft_clear_ast(&g_minishell.ast);
	ft_clear_envlst();
	// clear_history();
	// tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell.original_term);
}

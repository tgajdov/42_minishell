/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:41:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:51:35 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_minishell;

static void	*ft_init_minishell(char **env)
{
	ft_memset(&g_minishell, 0, sizeof(t_minishell));
	g_minishell.environ = env;
	ft_init_envlst();
	// g_minishell.stdin = dup(0);
	// g_minishell.stdout = dup(1);
	//tcgetattr(STDIN_FILENO, &minishell.original_term);
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	((void)ac, (void)av);
	ft_init_minishell(envp);
	while (1)
	{
		g_minishell.line = readline(PROMPT);
		if (g_minishell.line[0])
			add_history(g_minishell.line);
		ft_exec_builtin(ft_split(g_minishell.line, ' '));
	}
	return (0);
}

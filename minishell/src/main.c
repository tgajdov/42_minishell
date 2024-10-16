/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:41:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 22:12:31 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	*ft_init_minishell(char **env)
{
	ft_memset(&g_minishell, 0, sizeof(t_minishell));
	g_minishell.environ = env;
	ft_init_envlst();
	g_minishell.stdin = dup(0);
	g_minishell.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_minishell.original_term);
	return (NULL);
}

static void	ft_start_execution(void)
{
	signal(SIGQUIT, ft_sigquit_handler);
	// ft_init_tree(g_minishell.ast);
	if (g_minishell.heredoc_sigint)
	{
		// ft_clear_ast(&g_minishell.ast);
		g_minishell.heredoc_sigint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell.original_term);
	// g_minishell.exit_s = ft_exec_node(g_minishell.ast, false);
	// ft_clear_ast(&g_minishell.ast);
}

int	main(int ac, char **av, char **envp)
{
	((void)ac, (void)av);
	ft_init_minishell(envp);
	while (1)
	{
		ft_init_signals();
		g_minishell.line = readline(PROMPT);
		if (g_minishell.line[0])
			add_history(g_minishell.line);
		ft_start_execution();
		ft_exec_builtin(ft_split(g_minishell.line, ' '));
	}
	return (0);
}

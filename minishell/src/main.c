/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:41:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/28 15:57:51 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	*ft_init_minishell(char **env, t_minishell *g_minishell)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	ft_memset(g_minishell, 0, sizeof(t_minishell));
	g_minishell->environ = env;
	ft_init_envlst();
	g_minishell->stdin = dup(0);
	g_minishell->stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_minishell->original_term);
	return (NULL);
}

static void	ft_start_execution(t_minishell *g_minishell)
{
	signal(SIGQUIT, ft_sigquit_handler);
	// ft_init_tree(g_minishell.ast);
	if (g_minishell->heredoc_sigint)
	{
		// ft_clear_ast(&g_minishell.ast);
		g_minishell->heredoc_sigint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell->original_term);
	// g_minishell.exit_s = ft_exec_node(g_minishell.ast, false);
	// ft_clear_ast(&g_minishell.ast);
}

int	main(int argc, char **argv, char **env)
{
	t_minishell	*g_minishell; 
	g_minishell = get_g_minishell();
	((void)argc, (void)argv);
	ft_init_minishell(env, g_minishell);
	while (1)
	{
		ft_init_signals();
		g_minishell->line = readline(PROMPT);
		if (!g_minishell->line)
			(ft_clean_ms(),
				ft_putstr_fd("exit\n", 1), exit(g_minishell->exit_s));
		if (g_minishell->line[0])
			add_history(g_minishell->line);
		// g_minishell->tokens = ft_tokenize();
		if (!g_minishell->tokens)
			continue ;
		// g_minishell->ast = ft_parse();
		if (g_minishell->parse_err.type)
		{
			// ft_handle_parse_err();
			continue ;
		}
		ft_start_execution(g_minishell);
	}
	ft_garbage_collector(NULL, true);
	return (ft_clean_ms(), g_minishell->exit_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:41:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 17:43:05 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Initializes the global minishell structure, g_minishell.
 *
 * Copies the given environment variables into g_minishell->environ.
 * Initializes the environment list by calling ft_init_envlst().
 * Duplicates the standard input and output file descriptors and stores them
 * in g_minishell->stdin and g_minishell->stdout respectively.
 * Retrieves the current terminal attributes and stores them in
 * g_minishell->original_term.
 *
 * @param env The environment variables to copy into g_minishell->environ.
 * @return NULL
 */
static t_minishell	*ft_init_minishell(char **env)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	ft_memset(g_minishell, 0, sizeof(t_minishell));
	g_minishell->environ = env;
	ft_init_envlst();
	g_minishell->stdin = dup(0);
	g_minishell->stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_minishell->original_term);
	return (g_minishell);
}

/**
 * @brief Restores the original terminal attributes and executes the parsed
 * tree.
 *
 * Calls ft_sigquit_handler when the SIGQUIT signal is received.
 * Initializes the AST tree by calling ft_init_tree(g_minishell.ast).
 * If g_minishell->heredoc_sigint is true, clears the AST tree and sets the value
 * to false.
 * Restores the original terminal attributes using the stored attributes in
 * g_minishell->original_term.
 * Executes the parsed tree by calling ft_exec_node(g_minishell.ast, false) and
 * stores the exit status in g_minishell.exit_s.
 * Clears the AST tree by calling ft_clear_ast(&g_minishell.ast) after execution.
 */
static void	ft_start_execution(t_minishell *g_minishell)
{
	signal(SIGQUIT, ft_sigquit_handler);
	ft_init_tree(g_minishell->ast);
	if (g_minishell->heredoc_sigint)
	{
		ft_clear_ast(&g_minishell->ast);
		g_minishell->heredoc_sigint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &g_minishell->original_term);
	g_minishell->exit_s = ft_exec_node(g_minishell->ast, false);
	ft_clear_ast(&g_minishell->ast);
}

/**
 * @brief Cleans up the minishell state and exits the program when a line is not
 * returned from readline.
 *
 * Calls ft_clean_ms() to clean up the minishell state.
 * Prints "exit\n" to the standard output.
 * Exits the program with the exit status stored in g_minishell->exit_s.
 */
static void	ft_no_line_returned(void)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	ft_clean_ms();
	ft_putstr_fd("exit\n", 1);
	exit(g_minishell->exit_s);
}

/**
 * @brief The main entry point of the program.
 *
 * @details
 * The main loop of the program.
 * Calls ft_init_minishell to initialize the global state of the program.
 * Loops until the user types "exit".
 * In each iteration, calls ft_init_signals to set up the signal handlers.
 * Reads a line from the user with readline.
 * If the line is empty, prints "exit" and exits the program.
 * If the line is not empty, adds it to the history using add_history.
 * Calls ft_tokenize to tokenize the line.
 * If the tokenization fails, prints an error message and continues to the
 * next iteration.
 * Calls ft_parse to parse the tokens.
 * If the parsing fails, prints an error message and continues to the next
 * iteration.
 * Calls ft_start_execution to execute the parsed tree.
 * After the loop, calls ft_garbage_collector to free any remaining memory.
 * Returns the exit status of the last command.
 */
int	main(int argc, char **argv, char **env)
{
	t_minishell	*g_minishell;

	((void)argc, (void)argv);
	g_minishell = ft_init_minishell(env);
	while (1)
	{
		ft_init_signals();
		g_minishell->line = readline(PROMPT);
		if (!g_minishell->line)
			ft_no_line_returned();
		if (g_minishell->line[0])
			add_history(g_minishell->line);
		g_minishell->tokens = ft_tokenize();
		if (!g_minishell->tokens)
			continue ;
		g_minishell->ast = ft_parse();
		if (g_minishell->parse_err.type)
		{
			ft_handle_parse_err();
			continue ;
		}
		ft_start_execution(g_minishell);
	}
	ft_garbage_collector(NULL, true);
	return (ft_clean_ms(), g_minishell->exit_s);
}

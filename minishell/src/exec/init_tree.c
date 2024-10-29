/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:49:48 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:29:51 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Handles SIGINT signal for heredoc.
 * SIGINT is blocked in children processes, so we don't need to worry about
 * cleaning up the shell when the user presses Ctrl+C.
 *
 * @param signum Not used.
 */
static void	ft_heredoc_sigint_handler(int signum)
{
	(void)signum;
	ft_clean_ms();
	exit(SIGINT);
}

/**
 * Reads from standard input until a line equal to the delimiter is given.
 * If the delimiter is quoted, the input is not expanded.
 *
 * @param io The io node containing the delimiter.
 * @param p The pipe to write to.
 */
void	ft_heredoc(t_io_node *io, int p[2])
{
	char	*line;
	char	*quotes;

	signal(SIGINT, ft_heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_is_delimiter(io->value, line))
			break ;
		if (!*quotes)
			ft_heredoc_expander(line, p[1]);
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	ft_clean_ms();
	exit(0);
}

/**
 * Waits for the child process to finish, closes the write end of the pipe,
 * and resets the SIGQUIT signal handler.
 *
 * @param p The pipe to close the write end of.
 * @param pid The pid of the child process to wait for.
 *
 * @return true if the child process exited with SIGINT, false otherwise.
 */
static bool	ft_leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_false_sigint_child();
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

/**
 * @brief Initialize a leaf node by expanding its arguments and
 * processing any heredoc redirections.
 *
 * @param node The node to initialize.
 *
 * For each IO_HEREDOC redirection in the node's io_list, this function
 * forks a child process, sets the SIGQUIT handler to ignore the signal,
 * and executes ft_heredoc. The child process will read from standard
 * input until it receives a line matching the heredoc delimiter, at
 * which point it will exit and the parent process will close the write
 * end of the pipe and reset the SIGQUIT signal handler. If the child
 * process exits with SIGINT, this function will return immediately.
 *
 * For all other redirections, this function will simply expand the
 * redirection's value.
 *
 * Finally, this function will expand the node's arguments if it has
 * any.
 */
static void	ft_init_leaf(t_node *node)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			ft_true_sigint_child();
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p);
			if (ft_leave_leaf(p, &pid))
				return ;
			io->here_doc = p[0];
		}
		else
			io->expanded_value = ft_expand(io->value);
		io = io->next;
	}
}

/**
 * @brief Recursively initializes the abstract syntax tree by expanding
 * arguments and processing heredoc redirections.
 *
 * For each node in the tree, this function will call ft_init_leaf to
 * expand its arguments and process any heredoc redirections it may have.
 *
 * If the node is a binary operator (N_PIPE, N_AND, N_OR), this function
 * will recursively call itself on the left and right children of the node,
 * but only if the shell is not currently in heredoc mode.
 */
void	ft_init_tree(t_node *node)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	if (!node)
		return ;
	if (node->type == N_PIPE
		|| node->type == N_AND
		|| node->type == N_OR)
	{
		ft_init_tree(node -> left);
		if (!g_minishell->heredoc_sigint)
			ft_init_tree(node -> right);
	}
	else
		ft_init_leaf(node);
}

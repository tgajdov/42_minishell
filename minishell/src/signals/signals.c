/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:59:41 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:32:14 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Handles SIGINT signal.
 *
 * SIGINT is blocked in children processes, so we don't need to worry about
 * cleaning up the shell when the user presses Ctrl+C.
 *
 * If a child process is running, we just set the flag to false and set
 * heredoc_sigint flag to true, so that we don't exit the shell.
 *
 * Otherwise, we print a newline, replace the current line with an empty string,
 * move to a new line and redisplay the prompt.
 *
 * @param num Not used.
 */
static void	ft_sigint_handler(int num)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	(void)num;
	if (g_minishell->signint_child)
	{
		ft_putstr_fd("\n", 1);
		g_minishell->signint_child = false;
		g_minishell->heredoc_sigint = true;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/**
 * Handles SIGQUIT signal.
 *
 * SIGQUIT is not blocked in children processes, so we print "Quit: 3\n" to
 * the standard output.
 *
 * @param num Not used.
 */
void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

/**
 * Initializes signals for the shell.
 *
 * The shell catches SIGINT signals to handle them specially when a child
 * process is running. If a child process is running, we set a flag so that
 * we don't exit the shell when the user presses Ctrl+C.
 *
 * The shell ignores SIGQUIT signals, which are sent by the user when the
 * user presses Ctrl+\\.
 *
 * @return None.
 */
void	ft_init_signals(void)
{
	struct termios	term;
	t_minishell		*g_minishell;

	g_minishell = get_g_minishell();
	term = g_minishell->original_term;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_minishell->heredoc_sigint = false;
	g_minishell->signint_child = false;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
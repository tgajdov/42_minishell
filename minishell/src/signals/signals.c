/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:59:41 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/28 15:43:03 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

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
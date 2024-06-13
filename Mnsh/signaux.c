/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 13:07:11 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_print_newline(int signal)
{
	if (signal == 3)
		write(STDOUT_FILENO, "Quit: 3", 7);
	write(STDOUT_FILENO, "\n", 1);
}

void	default_signals(void)
{
	signal(SIGINT, signal_print_newline);
	signal(SIGQUIT, signal_print_newline);
}

static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	setup_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}

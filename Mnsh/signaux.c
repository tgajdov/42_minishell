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
	(void)signal;
	//rl_replace_line("", 0);
	rl_on_new_line();
}

void	default_signals(void)
{
	struct sigaction	act;

	act.sa_handler = &signal_print_newline;
	ft_memset(&act, 0, sizeof(act));
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		//rl_replace_line("", 0);
		write(STDOUT_FILENO,"\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	setup_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}

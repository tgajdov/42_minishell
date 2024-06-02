/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:37 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:28:46 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_print_newline(int signal)
{
	(void)signal;
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

static void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

//permet de ne pas prendre en compte le ctrl C
static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO,"\n", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	setup_signal(struct sigaction *sa)
{
	ignore_sigquit();
	sa->sa_handler = signal_handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	sigaction(SIGINT, sa, NULL);
}

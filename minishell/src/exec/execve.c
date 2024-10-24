/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/24 16:14:46 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_exec_child(t_node *node)
{
	t_path	path_status;
	int		tmp_status;
	int		fork_pid;

	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		tmp_status = ft_check_redirection(node);
		if (tmp_status != ENO_SUCCESS)
			(ft_clean_ms(), exit(ENO_GENERAL));
		path_status = ft_get_path((node -> expanded_args)[0]);
		if (path_status.err.no != ENO_SUCCESS)
		{
			tmp_status = ft_err_msg(path_status.err);
			(ft_clean_ms(), exit(tmp_status));
		}
		if (execve(path_status.path, node -> expanded_args,
				g_minishell.environ) == -1)
			(ft_clean_ms(), exit(1));
	}
	waitpid(fork_pid, &tmp_status, 0);
	g_minishell.signint_child = false;
	return (ft_get_exit_status(tmp_status));
}

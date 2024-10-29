/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:06 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:21:31 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks and executes redirections for a given node.
 * @param node The node to check for redirections.
 * @return ENO_SUCCESS if all redirections were successful, the error code
 *         otherwise.
 *
 * This function loops through the t_io_node list of the given node and checks
 * for the type of redirection. Depending on the type, it calls either ft_out,
 * ft_in or ft_append to execute the redirection. If any of these functions
 * return an error code, this function will return that error code.
 *
 * If the type of redirection is IO_HEREDOC, it will call dup2 to duplicate the
 * file descriptor of the heredoc to stdin and close the original file
 * descriptor.
 *
 * If the loop completes without finding any errors, this function will return
 * ENO_SUCCESS.
 */
int	ft_check_redirection(t_node *node)
{
	t_io_node	*tmp_io;
	int			tmp_status;

	tmp_io = node->io_list;
	while (tmp_io)
	{
		if (tmp_io->type == IO_OUT
			&& ft_out(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_IN
			&& ft_in(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_APPEND
			&& ft_append(tmp_io, &tmp_status) != ENO_SUCCESS)
			return (tmp_status);
		else if (tmp_io->type == IO_HEREDOC)
			(dup2(tmp_io->here_doc, 0), close(tmp_io->here_doc));
		tmp_io = tmp_io->next;
	}
	return (ENO_SUCCESS);
}

/**
 * @brief Resets the standard input and output file descriptors.
 *
 * This function resets the standard input and output file descriptors to
 * their original values stored in the global minishell structure. It is
 * intended to be used when commands are executed without pipes, restoring
 * the file descriptors to the original shell's stdin and stdout.
 *
 * @param piped If true, the function returns immediately without making
 *              any changes, as redirections should be preserved for
 *              piped commands.
 */
void	ft_reset_stds(bool piped)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	if (piped)
		return ;
	dup2(g_minishell->stdin, 0);
	dup2(g_minishell->stdout, 1);
}

/**
 * @brief Sets the signint_child flag to true in the global minishell structure.
 *
 * This function is used to indicate that a child process is currently being
 * executed, by setting the signint_child flag to true. This flag can be used
 * to handle signals differently when a child process is running.
 */
void	ft_true_sigint_child(void)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	g_minishell->signint_child = true;
}

/**
 * @brief Forks and executes the given node as a child process.
 *
 * This function forks the current process and executes the given node as a
 * child process. It first checks for any redirections in the node and
 * executes them with ft_check_redirection. If any redirections fail, it
 * returns the error code of the failed redirection.
 *
 * If all redirections are successful, it calls ft_get_path to get the path of
 * the command to execute and checks if the command exists. If the command does
 * not exist, it returns an error code.
 *
 * If the command exists, it calls execve to replace the current process image
 * with the new command. If execve fails, it returns an error code.
 *
 * The parent process waits for the child process to finish with waitpid and
 * returns the exit status of the child process.
 */
static int	ft_exec_child(t_node *node)
{
	t_path	path_status;
	int		tmp_status;
	int		fork_pid;

	ft_true_sigint_child();
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

/**
 * @brief Executes a simple command.
 *
 * This function executes a simple command given as a node in the abstract
 * syntax tree. It first checks for any redirections in the node and executes
 * them with ft_check_redirection. If any redirections fail, it returns the error
 * code of the failed redirection.
 *
 * If all redirections are successful, it checks if the first argument is a
 * built-in command and executes it with ft_exec_builtin. If the command does
 * not exist, it returns an error code.
 *
 * If the command exists, it calls ft_exec_child to fork and execute the
 * command as a child process.
 *
 * @param node The node to execute.
 * @param piped If true, ft_reset_stds will be called with piped set to true.
 *              This is used in the case of a piped command, where the
 *              redirections should be inherited to the next command in the
 *              pipe.
 * @return The exit status of the command, or the error code if any
 *         redirections or the command itself failed.
 */
int	ft_exec_simple_cmd(t_node *node, bool piped)
{
	int		tmp_status;

	if (!node -> expanded_args)
	{
		tmp_status = ft_check_redirection(node);
		return (ft_reset_stds(piped), (tmp_status && ENO_GENERAL));
	}
	else if (ft_is_builtin((node -> expanded_args)[0]))
	{
		tmp_status = ft_check_redirection(node);
		if (tmp_status != ENO_SUCCESS)
			return (ft_reset_stds(piped), ENO_GENERAL);
		tmp_status = ft_exec_builtin(node -> expanded_args);
		return (ft_reset_stds(piped), tmp_status);
	}
	else
		return (ft_exec_child(node));
}

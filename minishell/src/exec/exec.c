/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:23:40 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Set up the correct file descriptors for the child in a pipe execution.
 *
 * This function takes a node in the abstract syntax tree, a pipe file descriptor
 * and a direction. It sets up the correct file descriptors to either read from
 * the pipe or write to the pipe, and then executes the command represented by
 * the node. The status of the command is then passed to the exit function.
 *
 * @param node The node to execute
 * @param pfds The pipe file descriptors
 * @param direction The direction of the pipe (TD_LEFT or TD_RIGHT)
 */
static void
	ft_exec_pipe_child(t_node *node, int pfds[2], t_ast_direction direction)
{
	int	status;

	if (direction == TD_LEFT)
	{
		close(pfds[0]);
		dup2(pfds[1], STDOUT_FILENO);
		close(pfds[1]);
	}
	else if (direction == TD_RIGHT)
	{
		close(pfds[1]);
		dup2(pfds[0], STDIN_FILENO);
		close(pfds[0]);
	}
	status = ft_exec_node(node, true);
	(ft_clean_ms(), exit(status));
}

/**
 * @brief Converts a status returned by waitpid to an exit status.
 *
 * If the command was terminated by a signal, the exit status is set to 128
 * plus the signal number. Otherwise, the exit status is the value passed to
 * exit.
 *
 * @param status The status returned by waitpid.
 * @return The exit status of the command.
 */
int	ft_get_exit_status(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}

/**
 * @brief Set the signint_child flag in the global minishell structure to false.
 *
 * This function is used to indicate that a child process is no longer being
 * executed, by setting the signint_child flag to false. This flag can be used
 * to handle signals differently when a child process is no longer running.
 *
 * @return None.
 */
void	ft_false_sigint_child(void)
{
	t_minishell	*g_minishell;

	g_minishell = get_g_minishell();
	g_minishell->signint_child = false;
}

/**
 * @brief Executes a pipeline of commands represented by the syntax tree.
 *
 * This function creates a pipe, forks two child processes to execute
 * the left and right nodes of the pipeline, and sets up the appropriate
 * file descriptors for inter-process communication. It waits for both
 * child processes to finish and returns the exit status of the last
 * executed command. The function also manages the signal handling for
 * child processes by setting the signint_child flag.
 *
 * @param tree The root node of the syntax tree representing the pipeline.
 * @return The exit status of the last command in the pipeline, or
 *         ENO_GENERAL if forking fails.
 */
static	int	ft_exec_pipeline(t_node *tree)
{
	int	status;
	int	pfds[2];
	int	pid_l;
	int	pid_r;

	ft_true_sigint_child();
	pipe(pfds);
	pid_l = fork();
	if (!pid_l)
		ft_exec_pipe_child(tree->left, pfds, TD_LEFT);
	else
	{
		pid_r = fork();
		if (!pid_r)
			ft_exec_pipe_child(tree->right, pfds, TD_RIGHT);
		else
		{
			(close(pfds[0]), close(pfds[1]),
				waitpid(pid_l, &status, 0), waitpid(pid_r, &status, 0));
			ft_false_sigint_child();
			return (ft_get_exit_status(status));
		}
	}
	return (ENO_GENERAL);
}

/**
 * @brief Executes a node in the syntax tree.
 *
 * This function executes a node in the syntax tree by calling the appropriate
 * function based on the type of the node. If the node is a pipeline, it calls
 * ft_exec_pipeline. If the node is a logical operator, it calls itself
 * recursively. If the node is a command, it calls ft_exec_simple_cmd. It also
 * handles the piped flag, which is used to indicate if a command is part of a
 * pipeline or not.
 *
 * @param tree The node to execute.
 * @param piped If true, the command is part of a pipeline.
 * @return The exit status of the command, or ENO_GENERAL if anything fails.
 */
int	ft_exec_node(t_node *tree, bool piped)
{
	int	status;

	if (!tree)
		return (1);
	if (tree->type == N_PIPE)
		return (ft_exec_pipeline(tree));
	else if (tree->type == N_AND)
	{
		status = ft_exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return (ft_exec_node(tree->right, false));
		return (status);
	}
	else if (tree->type == N_OR)
	{
		status = ft_exec_node(tree->left, false);
		if (status == ENO_SUCCESS)
			return (status);
		return (ft_exec_node(tree->right, false));
	}
	else
		return (ft_exec_simple_cmd(tree, piped));
	return (ENO_GENERAL);
}

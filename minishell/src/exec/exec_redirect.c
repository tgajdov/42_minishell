/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:59:07 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:11:43 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Redirects the output of a command to a file specified in io_list
 * @param io_list The node containing the redirection information
 * @param status The status of the redirection
 * @return 0 on success, non-zero on error
 *
 * If the file does not exist, it is created. If the file already exists, its
 * contents are truncated. The file is created with permissions 0644.
 *
 * If the redirection fails, *status is set to a non-zero value.
 */
int	ft_out(t_io_node *io_list, int *status)
{
	int		fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg(
				(t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_write(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

/**
 * @brief Redirects the input of a command from a file specified in io_list
 * @param io_list The node containing the redirection information
 * @param status The status of the redirection
 * @return 0 on success, non-zero on error
 *
 * Opens the file in read-only mode and redirects STDIN to it. If the file
 * cannot be opened, *status is set to a non-zero value.
 */
int	ft_in(t_io_node *io_list, int *status)
{
	int		fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg(
				(t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_RDONLY);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_read(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	*status = 0;
	return (*status);
}

/**
 * @brief Appends the output of a command to a file specified in io_list
 * @param io_list The node containing the redirection information
 * @param status The status of the redirection
 * @return 0 on success, non-zero on error
 *
 * Opens the file in append mode and redirects STDOUT to it. If the file
 * cannot be opened, *status is set to a non-zero value.
 */
int	ft_append(t_io_node *io_list, int *status)
{
	int	fd;

	if (!io_list->expanded_value || io_list->expanded_value[1])
	{
		*status = ft_err_msg(
				(t_err){ENO_GENERAL, ERRMSG_AMBIGUOUS, io_list->value});
		return (*status);
	}
	fd = open(io_list->expanded_value[0], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		*status = ft_err_msg(ft_check_write(io_list->expanded_value[0]));
		return (*status);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	*status = 0;
	return (0);
}

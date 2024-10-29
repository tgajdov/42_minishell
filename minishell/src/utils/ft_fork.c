/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:58:34 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:32:28 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Creates a child process using fork().
 *
 * This function wraps the fork() system call to create a new process.
 * If the fork operation fails, it calls panic() with an error message.
 * On success, the function returns the process ID of the child process
 * to the parent and returns 0 to the child process.
 *
 * @return The process ID of the child process to the parent, or 0 to the child.
 */
int	ft_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		panic("fork error");
	return (pid);
}
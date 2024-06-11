/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:48 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 15:23:51 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "<"
int	redirect_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("mnsh: %s: No such file or director\n", filename);
		return (0);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (error_zero(4));
	if (close(fd) == -1)
		return (error_zero(5));
	return (1);
}

// ">"
int	redirect_output(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IROTH);
	if (fd == -1)
		return (error_zero(3));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (error_zero(4));
	if (close(fd) == -1)
		return (error_zero(5));
	return (1);
}

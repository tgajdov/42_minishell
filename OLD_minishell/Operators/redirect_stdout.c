/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:55 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:42:06 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// (>>)
int	redirect_stdout_append(char *fichier)
{
	int	fd;

	fd = open(fichier, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (error_zero(3));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (error_zero(4));
	if (close(fd) == -1)
		return (error_zero(5));
	return (1);
}

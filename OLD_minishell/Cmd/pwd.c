/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:59 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:56:13 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*cwd;
	ssize_t	len;
	ssize_t	w;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (error_zero(9));
	len = ft_strlen(cwd);
	w = write(STDOUT_FILENO, cwd, len);
	if (w < len)
	{
		free(cwd);
		return (error_zero(7));
	}
	write (STDOUT_FILENO, "\n", 1);
	free(cwd);
	return (1);
}

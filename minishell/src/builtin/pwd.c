/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:42 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 22:40:03 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	builtin_pwd(char **envp)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	cwd = ft_getenv("PWD", envp);
	if (cwd == NULL)
		return (0);
	ft_putstr_fd(cwd, STDOUT_FILENO);
	write (STDOUT_FILENO, "\n", 1);
	return (1);
}

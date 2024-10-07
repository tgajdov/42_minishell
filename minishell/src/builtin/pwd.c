/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:34:42 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/07 16:37:25 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (0);
	ft_putstr_fd(cwd, STDOUT_FILENO);
	free(cwd);
	write (STDOUT_FILENO, "\n", 1);
	return (1);
}

/* Check si getcwd agit sur le directory ou on a lancé 
 * le programme ou s'il analyse le PATH ou on lance la commande*/
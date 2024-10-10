/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:58 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/10 17:41:58 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	builtin_echo(char *str, t_builtin_code code)
{
	/*	tolower les arg de commandes avant la fonction
	*/
	char *tmp;
	if (code == ECHON)
		tmp = ft_strtrim(str, "echo -n ");
	else
		tmp = ft_strtrim(str, "echo ");
	ft_putstr_fd(tmp, STDOUT_FILENO); //tester avec !str
	if(code == ECHO)
		write (STDOUT_FILENO, "\n", 1);
	free(tmp);
	return (0);
}
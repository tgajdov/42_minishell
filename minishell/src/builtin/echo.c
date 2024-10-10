/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:58 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/10 13:30:59 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

typedef enum e_echo_code
{
	ECHO,
	ECHON
}		t_echo_code;

t_echo_code	get_echo_code(char *str)
{
	if (!ft_strncasecmp(str, "echo", 4))
		return (ECHO);
	if (!ft_strncasecmp(str, "echo -n", 7))
		return (ECHON);
	return (-1);
}

int builtin_echo(char *str, t_echo_code code, int output_fd)
{
	ft_putstr_fd(str, output_fd); //tester avec !str
	if(code == ECHO)
		write (output_fd, "\n", 1);
	return (0);
}
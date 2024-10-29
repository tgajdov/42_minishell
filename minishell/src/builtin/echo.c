/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:33:58 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 12:55:25 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if the argument string is a valid option for the echo command.
 *
 * @param s The argument string to check.
 * @return 1 if the string is a valid option, 0 otherwise.
 *
 * The only valid option for the echo command is "-n".
 * If the string does not start with a '-' character,
 * the function returns 0.
 * If the string does not contain only 'n' characters after the '-',
 * the function returns 0.
 */
static int	ft_check_option(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Built-in echo command
 * @param args Command-line arguments
 * @return 0 if successful, 1 if not
 *
 * The echo command prints its arguments to the standard output,
 * followed by a newline.
 * If the -n option is present, the newline is not printed.
 * If no arguments are given, nothing is printed.
 *
 * @note This function does not handle errors, so it will not return 1.
 */
int	builtin_echo(char **args)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	while (args[i] != NULL && ft_check_option(args[i]) == 1)
	{
		opt = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (opt == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:50 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 13:31:25 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * panic - Outputs an error message to standard error and terminates the program.
 * @str: The error message to be displayed.
 *
 * This function writes "minishell: " followed by the provided error message
 * and a newline to the standard error output. It then terminates the program
 * with an exit code of 1.
 */
void	panic(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

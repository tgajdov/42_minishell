/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_g_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:12:47 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:33:15 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Returns a pointer to the global minishell struct.
 *
 * The global minishell struct keeps track of state that is global to the
 * entire shell, such as the environment, the current working directory,
 * the standard input and output, and whether or not the shell is currently
 * executing a command.
 *
 * Returns:
 *  A pointer to the global minishell struct.
 */
t_minishell	*get_g_minishell(void)
{
	static t_minishell	g_minishell;
	return (&g_minishell);
}
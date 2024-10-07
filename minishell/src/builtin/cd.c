/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/07 15:37:54 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")))
		{
			printf("%s\n", strerror(errno));
			return (1);
		}
	}
	else if (chdir(args[1]) != 0)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	return (0);
}

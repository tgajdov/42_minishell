/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/10 18:00:21 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	builtin_cd(char *cmd_str)
{
	printf ("cmd_str : %s\nIl faut checker si builtin_cd fonctionne dans un minishell qui tourne\n", cmd_str);
	return (0);
/* 	char **tmp;

	tmp = ft_split(cmd_str, ' ');
	if (!tmp)
		return (1);
	if (tmp[1] == NULL)
	{
		if (chdir(getenv("HOME")))
		{
			printf("%s\n", strerror(errno));
			return (1);
		}
	}
	else if (chdir(tmp[1]) != 0)
	{
		printf("%s\n", strerror(errno));
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0); */
}

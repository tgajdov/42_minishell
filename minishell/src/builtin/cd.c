/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 16:26:36 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

static const char	*get_cd_path(char **tmp)
{
	const char	*path;

	if (tmp[1] == NULL)
	{
		path = getenv("HOME");
		if (!path)
			printf("cd: HOME not set\n");
	}
	else
		path = tmp[1];
	return (path);
}

int	builtin_cd(char *cmd_str)
{
	char		**tmp;
	const char	*path;

	DEBUG("IM HERE");
	tmp = ft_split(cmd_str, ' ');
	if (!tmp)
		return (1);
	path = get_cd_path(tmp);
	if (!path || chdir(path) != 0)
	{
		if (path)
			printf("cd: %s: %s\n", path, strerror(errno));
		ft_free_tab(tmp);
		return (1);
	}
	ft_free_tab(tmp);
	return (0);
}


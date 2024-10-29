/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:32:07 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:24:12 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Construct a full path from a command and a PATH environment variable value.
 *
 * @param path Value of the PATH environment variable.
 * @param cmd Command to append to each path in the PATH value.
 *
 * @return A t_path structure containing an error and a path.
 *   - If the command is not found in the PATH, the error is ENO_NOT_FOUND and the path is NULL.
 *   - If the command is found in the PATH, the error is ENO_SUCCESS and the path is the full path of the command.
 */
static t_path	ft_get_env_path(char *path, char *cmd)
{
	size_t	i;
	t_err	err;
	char	*cmd_path;
	char	**split_path;

	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		cmd_path = ft_garbage_collector(ft_strjoin_with_f(
					ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
		err = ft_check_exec(cmd_path, true);
		if (err.no == ENO_SUCCESS)
			return ((t_path){(t_err){ENO_SUCCESS, 42, cmd_path}, cmd_path});
		i++;
	}
	ft_free_char2(split_path);
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
}

/**
 * @brief Retrieves the executable path for a given command.
 *
 * @param cmd The command for which to find the executable path.
 *
 * @return A t_path structure containing an error and a path.
 *   - If the command is an empty string, returns ENO_NOT_FOUND with a NULL path.
 *   - If the command contains a '/', checks and returns its executable status.
 *   - If the command is found in the PATH environment variable, returns its full path.
 *   - If not found, returns ENO_NOT_FOUND with a NULL path.
 */
t_path	ft_get_path(char *cmd)
{
	char	*value;

	if (*cmd == '\0')
		return ((t_path){
			(t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, cmd}, NULL});
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return ((t_path){ft_check_exec(cmd, false), cmd});
	value = ft_get_envlst_val("PATH");
	if (value)
		return (ft_get_env_path(value, cmd));
	return ((t_path){(t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, cmd}, NULL});
}

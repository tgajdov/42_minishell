/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:18 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 16:55:09 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	traduct_cmd(t_token *tokens, t_export *alloctrack)
{
	char	**tmp;

	tmp = malloc(2 * sizeof(char *));
	if (!tmp)
		return (error_zero(2));
	tmp[0] = ft_strdup(tokens->cmd);
	tmp[1] = NULL;
	free(tokens->cmd);
	tmp = ft_parsing(tmp, alloctrack);
	if (tmp[0] && tmp[0][0] != '\0')
		tokens->cmd = ft_strdup(tmp[0]);
	else
		tokens->cmd = NULL;
	free_tab(tmp);
	return (1);
}

static int	other_parse(char *cmd, t_export *alloctrack)
{
	if ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
		return (1);
	if (ft_strcasecmp(cmd, "echo", 4) != 0 && ft_strcasecmp(cmd, "cd", 2) != 0
		&& ft_strcasecmp(cmd, "pwd", 3) != 0
		&& ft_strcasecmp(cmd, "export", 6) != 0
		&& ft_strcasecmp(cmd, "unset", 5) != 0
		&& ft_strcasecmp(cmd, "env", 3) != 0
		&& ft_strcasecmp(cmd, "exit", 4) != 0 && cmd[0] != '\0')
	{
		printf("mnsh : %s: command not found\n", cmd);
		alloctrack->status = 127;
		return (0);
	}
	return (1);
}

int	command_not_found(t_token *tokens, t_export *alloctrack)
{
	if (!tokens->cmd)
		return (0);
	if (!traduct_cmd(tokens, alloctrack))
		return (0);
	if (!tokens->cmd)
		return (0);
	else if (!error_echo(tokens->cmd, alloctrack))
		return (0);
	else if (!error_cd(tokens->cmd, alloctrack))
		return (0);
	else if (!error_pwd(tokens->cmd, alloctrack))
		return (0);
	else if (!error_export_unset_env(tokens->cmd, alloctrack))
		return (0);
	else if (!error_exit(tokens->cmd, alloctrack))
		return (0);
	else if (!other_parse(tokens->cmd, alloctrack))
		return (0);
	else
		return (1);
}

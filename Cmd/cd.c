/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:18 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:59 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char *path, t_export *alloctrack)
{
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(getcwd(NULL, 0) + 1)));
	ft_strlcpy(temp, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0))+1);
	if (chdir(path) == -1)
		return (error_zero(8));
	ft_strlcpy(get_var(alloctrack, "OLDPWD"), temp, ft_strlen(temp)+1);
	ft_strlcpy(get_var(alloctrack, "PWD"), getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0))+1);
	free(temp);
	return (1);
}

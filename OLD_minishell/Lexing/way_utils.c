/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:42:28 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 18:43:20 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	complete_way(char **way, char *cmd, char **tmp, int t)
{
	int	i;
	int	j;

	i = -1;
	while (way[t][++i])
		(*tmp)[i] = way[t][i];
	j = -1;
	while (cmd[++j])
		(*tmp)[i++] = cmd[j];
	(*tmp)[i] = '\0';
}

char	**check_if_good_way(char **way, char *cmd)
{
	char	**good_way;
	int		i;

	i = 0;
	while (way[i] && ft_strcasecmp(way[i], cmd, ft_strlen(way[i])) != 0)
		i++;
	if (way[i] && ft_strcasecmp(way[i], cmd, ft_strlen(way[i])) == 0)
	{
		good_way = malloc(sizeof(char *) * 2);
		if (!good_way)
			return (0);
		good_way[0] = ft_strdup(cmd);
		good_way[1] = NULL;
		return (good_way);
	}
	return (NULL);
}

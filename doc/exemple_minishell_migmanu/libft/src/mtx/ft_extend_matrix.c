/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:30:30 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/12/04 11:57:17 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_extend_matrix(char **matrix, char *str)
{
	char	**new;
	int		len;
	int		i;

	i = -1;
	new = NULL;
	if (!str)
		return (matrix);
	len = ft_matrixlen(matrix);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new)
		return (NULL);
	new[len + 1] = NULL;
	while (++i < len)
	{
		new[i] = ft_strdup(matrix[i]);
		if (!new[i])
		{
			ft_matrixfree(&matrix);
			ft_matrixfree(&new);
		}
	}
	new[i] = ft_strdup(str);
	ft_matrixfree(&matrix);
	return (new);
}

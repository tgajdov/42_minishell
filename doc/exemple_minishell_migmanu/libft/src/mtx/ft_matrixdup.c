/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:29:28 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/11/21 12:29:39 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_matrixdup(char **tokens)
{
	int		i;
	int		size;
	char	**tmp;

	if (!tokens || !tokens[0])
		return (NULL);
	size = ft_matrixlen(tokens);
	tmp = malloc((size + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	i = -1;
	while (tokens[++i])
	{
		tmp[i] = ft_strdup(tokens[i]);
		if (!tmp[i])
		{
			ft_matrixfree(&tmp);
			return (NULL);
		}
	}
	tmp[i] = NULL;
	return (tmp);
}

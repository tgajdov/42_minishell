/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:22 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 17:07:04 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parsing(char **argument, t_export *alloctrack)
{
	int	t;

	argument = replace_argument(argument, alloctrack);
	t = -1;
	while (argument[++t] != NULL)
	{
		if (argument[t] == NULL)
			break ;
		argument[t] = erase_quote(argument[t]);
		if (!argument[t])
			return (NULL);
	}
	return (argument);
}

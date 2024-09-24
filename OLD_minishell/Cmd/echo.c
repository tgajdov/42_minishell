/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:30 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:35 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char *input)
{
	ssize_t		len;
	ssize_t		w;

	len = ft_strlen(input);
	w = write (STDOUT_FILENO, input, len);
	if (w < len)
		return (error_zero(7));
	return (1);
}

int	echon(char *input)
{
	char	*tmp;
	ssize_t	i;
	ssize_t	w;

	i = ft_strlen(input);
	tmp = malloc(i * sizeof(char));
	if (!tmp)
		return (0);
	tmp = ft_strdup(input);
	i = 0;
	while (tmp[i])
	{
		w = write(STDOUT_FILENO, &tmp[i], 1);
		if (w < 1)
			return (error_zero(7));
		i++;
	}
	free(tmp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:40 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:41:53 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_deux(t_export *alloctrack, int n)
{
	int		i;
	ssize_t	len;
	ssize_t	w;

	i = 0;
	while (alloctrack->export_env[i])
	{
		if ((ft_strrchr(alloctrack->export_env[i], '=')) || (n == 21))
		{
			if (n == 21)
				write(STDOUT_FILENO, "declare -x ", 11);
			len = ft_strlen(alloctrack->export_env[i]);
			w = write(STDOUT_FILENO, alloctrack->export_env[i], len);
			if (w < len)
				return (error_zero(7));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}
	return (1);
}

int	ft_env(t_export *alloctrack, int n)
{
	int		i;
	ssize_t	len;
	ssize_t	w;

	if (!alloctrack->environ[0])
	{
		printf("mnsh : No environment variables detected.\n");
		return (0);
	}
	i = 0;
	while (alloctrack->environ[i])
	{
		if (n == 21)
			write(STDOUT_FILENO, "declare -x ", 11);
		len = ft_strlen(alloctrack->environ[i]);
		w = write(STDOUT_FILENO, alloctrack->environ[i++], len);
		if (w < len)
			return (error_zero(7));
		write(STDOUT_FILENO, "\n", 1);
	}
	if (!ft_env_deux(alloctrack, n))
		return (error_zero(7));
	return (1);
}

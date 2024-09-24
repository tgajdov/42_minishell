/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:20:48 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 13:43:01 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(int num, t_export *alloctrack)
{
	if (num == 0)
		exit(EXIT_SUCCESS);
	else if (num == 255)
	{
		free_alloctrack(alloctrack);
		exit(num);
	}
	else
	{
		free_alloctrack(alloctrack);
		printf("exit\n");
		exit(num);
	}
}

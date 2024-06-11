/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:43 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 15:23:34 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_zero(int num)
{
	if (num == 1)
		perror("mnsh : Error Opendir");
	if (num == 2)
		perror("mnsh : Allocated memory failed");
	if (num == 3)
		perror("mnsh : Openfile");
	if (num == 4)
		perror("mnsh : Redirecting Dup2");
	if (num == 5)
		perror("mnsh : Closing file");
	if (num == 6)
		perror("mnsh : Read Error");
	if (num == 7)
		printf("mnsh : Writing Error\n");
	if (num == 8)
		perror("");
	if (num == 9)
		perror("mnsh : pwd");
	if (num == 10)
		perror("mnsh : fork");
	if (num == 11)
		perror("mnsh : pipe");
	if (num == 12)
		perror("mnsh : execve");
	return (0);
}

int	error_neg(int n)
{
	if (n == 1)
		printf("mnsh : Writing Error\n");
	return (-1);
}

char	*error_null(int n)
{
	if (n == 1)
		perror("mnsh : Allocated memory failed");
	if (n == 2)
		printf("mnsh : Writing Error\n");
	return (NULL);
}

int	err_exit(int num)
{
	if (num == 1)
		perror("mnsh : execve");
	exit (1);
}

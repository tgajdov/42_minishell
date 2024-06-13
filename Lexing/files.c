/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:11:04 by tgajdov           #+#    #+#             */
/*   Updated: 2024/06/13 16:11:35 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

int	file_exists(const char *filename)
{
	int	exists;

	exists = access(filename, F_OK) != -1;
	return (exists);
}

static int	create_empty_file(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		printf("mnsh: %s: No such file or directory\n", filename);
		return (0);
	}
	if (close(fd) == -1)
		return (error_zero(5));
	return (1);
}

static int	check_if_empty_file(char *filename)
{
	if (file_exists(filename))
		return (1);
	else if (create_empty_file(filename) == 0)
		return (0);
	return (1);
}

int	check_for_next_redirect(t_token **token, t_export *alloctrack)
{
	while ((*token)->next != NULL && (*token)->operator != NULL \
			&& (*token)->next->operator \
			&& (!ft_strncmp((*token)->next->operator, (*token)->operator, 1)))
	{
		if (ft_strncmp((*token)->operator, ">", 1) == 0)
		{
			if (ft_strncmp((*token)->operator, ">>", 2) == 0)
			{
				if (check_if_empty_file((*token)->arg_operator) == 0)
				{
					alloctrack->status = 1;
					return (1);
				}
			}
			else
			{
				if (create_empty_file((*token)->arg_operator) == 0)
				{
					alloctrack->status = 1;
					return (1);
				}
			}
			(*token) = (*token)->next;
		}
		else if ((ft_strncmp((*token)->operator, "<", 1) == 0) \
				&& (ft_strncmp((*token)->operator, "<<", 2) != 0) \
				&& (ft_strncmp((*token)->next->operator, "<<", 2) != 0))
		{
			if (file_exists((*token)->arg_operator)
				|| is_directory((*token)->arg_operator))
				(*token) = (*token)->next;
			else
				return (1);
		}
	}
	return (0);
}

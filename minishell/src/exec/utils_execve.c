/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:47:47 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:30:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Frees a pointer and sets it to NULL.
 *
 * @param ptr The pointer to free and set to NULL.
 */
static void	ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

/**
 * @brief A garbage collector that stores pointers in a linked list.
 *
 * @details
 * This function stores any pointer passed to it in a linked list.
 * When the clean argument is set to true, the linked list is cleared
 * and the function returns NULL.
 *
 * @param ptr A pointer to a piece of memory to store in the linked list.
 * @param clean If set to true, the linked list will be cleared and the
 * function will return NULL.
 * @return The stored pointer when clean is false, NULL when clean is true.
 */
void	*ft_garbage_collector(void *ptr, bool clean)
{
	static t_list	*garbage_list;

	if (clean)
	{
		ft_lstclear(&garbage_list, ft_del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}

/**
 * Checks if a given string matches a delimiter, ignoring quotes in the delimiter.
 *
 * This function compares the provided string against the delimiter character by character,
 * ignoring any quote characters ('"' or '\'') in the delimiter. The function returns true
 * if the string matches the delimiter after ignoring quotes, otherwise it returns false.
 *
 * @param delimiter The delimiter string, which may contain quotes to be ignored.
 * @param str The string to be compared against the delimiter.
 * @return true if the string matches the delimiter after ignoring quotes, false otherwise.
 */
bool	ft_is_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!*delimiter);
}

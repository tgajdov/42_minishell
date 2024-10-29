/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:25:47 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:32:56 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Reallocate memory block.
 * 
 * This function change the size of the memory block pointed to by ptr.
 * The contents will be unchanged in the range from the start of the region up to
 * the minimum of the old and new sizes. If the new size is larger than the old size,
 * the added memory will NOT be initialized.
 * 
 * @param ptr a pointer to the memory block to be reallocated
 * @param old_size the size of the old memory block
 * @param new_size the size of the new memory block
 * 
 * @return a pointer to the reallocated memory block, or NULL if the request fails
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size > new_size)
		old_size = new_size;
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

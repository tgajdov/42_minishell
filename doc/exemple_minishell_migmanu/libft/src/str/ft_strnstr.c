/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:11:12 by johnavar          #+#    #+#             */
/*   Updated: 2023/07/04 17:37:45 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (substr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == substr[j])
		{
			while (str[i + j] == substr[j] && i + j < n)
			{
				if (substr[j + 1] == '\0')
					return ((char *)str + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

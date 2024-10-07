/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:08:06 by johnavar          #+#    #+#             */
/*   Updated: 2023/07/04 17:45:43 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*new_str;
	char		*new_str_start;
	const char	*s1_end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_end = s1 + ft_strlen(s1) - 1;
	while (s1_end > s1 && ft_strchr(set, *s1_end))
		s1_end--;
	len = s1_end - s1;
	new_str = (char *)malloc((len + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str_start = new_str;
	while (s1 <= s1_end)
		*new_str++ = *s1++;
	*new_str = '\0';
	return (new_str_start);
}

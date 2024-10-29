/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:47:51 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:31:00 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Compares up to n characters of strings s1 and s2, ignoring case.
 *
 * The comparison is done using unsigned characters, so that '\200' is greater
 * than '\0'.
 *
 * \return 0 if the strings are equal, a negative value if s1 is less than
 * s2, and a positive value if s1 is greater than s2.
 */
int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	int		c1;
	int		c2;
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		c1 = ft_tolower(s1[i]);
		c2 = ft_tolower(s2[i]);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

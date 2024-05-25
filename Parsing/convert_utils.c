/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:03 by brferran          #+#    #+#             */
/*   Updated: 2024/05/24 15:07:52 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui rend soit la valeur du tableau d'environnement soit 
// la derniere valeur retourné par la programme.
char	*choose_convert(char *dollars, t_export *alloctrack)
{
	char	*d;

	if (dollars[1] == '?')
		d = last_return(alloctrack->status);
	else
		d = dollars_lex(dollars + 1, alloctrack);
	free(dollars);
	return (d);
}

// Fonction qui cherche une variable dans le tableau d'environnement et..
// ..renvoi un pointeur sur sa valeur si elle est trouvée sinon return NULL.
char	*dollars_lex(char *var_name, t_export *alloctrack)
{
	char	*value;
	int		found;
	int		t;
	int		len;

	t = 0;
	found = 0;
	len = ft_strlen(var_name);
	while (alloctrack->environ[t])
	{
		if (ft_strncmp(var_name, alloctrack->environ[t], len) == 0
			&& alloctrack->environ[t][ft_strlen(var_name)] == '=')
		{
			value = ft_strdup(strchr(alloctrack->environ[t], '='));
			found = 1;
		}
		t++;
	}
	if (found == 0)
		value = NULL;
	value = value + 1;
	return (value);
}

// Fonction qui concatène src à la fin de dst.
char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;
	char	*cat;

	if (!dst && !src)
		return (NULL);
	i = ft_strlen(dst) + ft_strlen(src) + 1;
	cat = malloc(i * sizeof(char));
	if (!cat)
		return (error_null(1));
	i = 0;
	while (dst[i])
	{
		cat[i] = dst[i];
		i++;
	}
	j = 0;
	while (src[j])
		cat[i++] = src[j++];
	cat[i] = '\0';
	return (cat);
}

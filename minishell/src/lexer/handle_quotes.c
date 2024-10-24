/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengelba <dengelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:57:24 by dengelba          #+#    #+#             */
/*   Updated: 2024/10/24 14:57:24 by dengelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/struct.h"

int	handle_quotes(int i, char *str, char quote)
{
	int	j;

	j = 0;
	if (str[i + j] == quote)
	{
		j++;
		while (str[i + j] != quote && str[i + j])
			j++;
		j++;
	}
	return (j);
}

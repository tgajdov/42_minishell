/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:08 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 14:01:56 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*last_return(int status)
{
	char	*state;

	state = ft_itoa(status);
	if (!state)
		return (NULL);
	return (state);
}

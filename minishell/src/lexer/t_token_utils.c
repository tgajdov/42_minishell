/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengelba <dengelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:04:38 by dengelba          #+#    #+#             */
/*   Updated: 2024/10/24 15:04:38 by dengelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/struct.h"

t_token	*ft_lexernew(char *str, int token)
{
	t_token		*new_element;
	static int	i = 0;

	new_element = (t_token *)malloc(sizeof(t_token));
	if (!new_element)
		return (0);
	new_element->value = str;
	new_element->type = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_lexeradd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

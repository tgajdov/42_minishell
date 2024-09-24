/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:38:23 by brferran          #+#    #+#             */
/*   Updated: 2023/10/25 18:35:51 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*supp;

	if (lst)
	{
		while (*lst)
		{
			supp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = supp;
		}
	}
}

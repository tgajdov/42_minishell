/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:54:45 by brferran          #+#    #+#             */
/*   Updated: 2023/10/25 18:19:01 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*nobj;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst != NULL)
	{
		nobj = ft_lstnew(f(lst->content));
		if (!nobj)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, nobj);
		lst = lst->next;
	}
	return (nlist);
}

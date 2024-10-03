/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:28:30 by tgajdov           #+#    #+#             */
/*   Updated: 2023/10/27 16:47:43 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*copie_lst;

	copie_lst = lst;
	i = 0;
	while (copie_lst)
	{
		copie_lst = copie_lst->next;
		i++;
	}
	return (i);
}

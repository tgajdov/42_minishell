/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:47:17 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/07/04 16:48:06 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

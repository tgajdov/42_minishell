/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:52:47 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/05 15:25:42 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_printstr(char *str, int len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		len += 6;
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			len++;
		}
	}
	return (len);
}

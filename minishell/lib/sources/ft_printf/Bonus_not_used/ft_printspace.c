/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:59 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:42 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printspace(int nb, int len)
{
	len = ft_printchar(' ', len);
	len = ft_printnbr(nb, len);
	return (len);
}

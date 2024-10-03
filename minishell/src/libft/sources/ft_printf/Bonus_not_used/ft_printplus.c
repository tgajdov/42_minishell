/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printplus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:28 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/04 15:16:26 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printplus(int nb, int len)
{
	len = ft_printchar('+', len);
	len = ft_printnbr(nb, len);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xs_xl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:04:43 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/04 15:10:58 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_xs_xl(const char *format, size_t add, int len, int i)
{
	i++;
	if (format[i] == 'x')
	{
		len = ft_printstr("0x", len);
		len = ft_print_xs(add, len);
	}
	else if (format[i] == 'X')
	{
		len = ft_printstr("0X", len);
		len = ft_print_xl(add, len);
	}
	return (len);
}

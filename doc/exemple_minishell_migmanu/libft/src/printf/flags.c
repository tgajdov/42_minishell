/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/09/19 16:54:40 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_flag_left(t_print *flags)
{
	flags->left = 1;
	flags->zero = 0;
}

static int	ft_flag_prec(const char *format, int i, va_list *ap, t_print *flags)
{
	int	j;

	j = i + 1;
	if (flags->zero == 1)
		flags->zero = 0;
	if (format[j] == '*')
	{
		flags->precision = va_arg(*ap, int);
		return (++j);
	}
	flags->precision = 0;
	while (ft_isdigit(format[j]))
	{
		flags->precision = (flags->precision * 10) + (format[j] - '0');
		j++;
	}
	return (j);
}

static void	ft_flag_star(va_list *ap, t_print *flags)
{
	flags->star = 1;
	flags->width = va_arg(*ap, int);
	if (flags->width < 0)
	{
		flags->left = 1;
		flags->width = -flags->width;
	}
}

static void	ft_flag_digit(char c, t_print *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}

int	ft_parse_flags(const char *format, int i, va_list *ap, t_print *flags)
{
	while (format[++i] && ft_isflag(format[i]))
	{
		if (format[i] == '-')
			ft_flag_left(flags);
		if (format[i] == '#')
			flags->hash = 1;
		if (format[i] == ' ')
			flags->space = 1;
		if (format[i] == '+')
			flags->plus = 1;
		if (format[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_flag_prec(format, i, ap, flags);
		if (format[i] == '*')
			ft_flag_star(ap, flags);
		if (ft_isdigit(format[i]))
			ft_flag_digit(format[i], flags);
		if (ft_istype(format[i]))
		{
			flags->spec = format[i];
			break ;
		}
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:58:43 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 17:49:49 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This header contains all the colors used by the minishell
*/

// colors.h
#ifndef COLORS_H
# define COLORS_H

// Reset
# define C_RESET   "\x1b[0m"

// Regular Colors
# define BLACK   "\x1b[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1b[37m"

// Bold
# define B_BLACK   "\x1b[1;30m"
# define B_RED     "\x1b[1;31m"
# define B_GREEN   "\x1b[1;32m"
# define B_YELLOW  "\x1b[1;33m"
# define B_BLUE    "\x1b[1;34m"
# define B_MAGENTA "\x1b[1;35m"
# define B_CYAN    "\x1b[1;36m"
# define B_WHITE   "\x1b[1;37m"

// Background
# define BG_BLACK   "\x1b[40m"
# define BG_RED     "\x1b[41m"
# define BG_GREEN   "\x1b[42m"
# define BG_YELLOW  "\x1b[43m"
# define BG_BLUE    "\x1b[44m"
# define BG_MAGENTA "\x1b[45m"
# define BG_CYAN    "\x1b[46m"
# define BG_WHITE   "\x1b[47m"

#endif // COLORS_H
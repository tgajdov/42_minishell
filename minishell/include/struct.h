/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:11:39 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 15:03:18 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}	t_err_no;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_scmd
{
	char	**full_cmd;
	char	*path;
	int		in_fd;
	int		out_fd;
}	t_scmd;

typedef struct s_minishell {
	int				exit_s;
	int				stdin;
	int				stdout;
	char			**environ;
	t_env			*envlst;
	struct termios	original_term;
}			t_minishell;

extern t_minishell	g_minishell;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:11:39 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 12:40:07 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef enum e_builtin_code
{
	CD = 1,
	ENV,
	ECHON,
	ECHO,
	EXPORT,
	EXIT,
	PWD,
	UNSET
}		t_builtin_code;

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}	t_err_no;

typedef struct s_scmd
{
	char	**full_cmd;
	char	*path;
	int		in_fd;
	int		out_fd;
}	t_scmd;

typedef struct s_command_table {

	char	**av;
	char	**envp;
	
	char	*cmd;
	char	*cmd_path;

	int		exit_status;	
}			t_command_table;

#endif
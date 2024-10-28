/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:11:39 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/28 22:35:05 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUI,
	ERRMSG_FILEISDIR
}	t_err_msg;

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}	t_err_no;

typedef enum e_ast_direction
{
	TD_LEFT,
	TD_RIGHT
}	t_ast_direction;

typedef struct s_err
{
	t_err_no	no;
	t_err_msg	msg;
	char		*cause;
}	t_err;

typedef struct s_path
{
	t_err	err;
	char	*path;
}	t_path;

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_O_PARENT,
	T_C_PARENT,
	T_AND,
	T_OR,
	T_NL,
}	t_token_type;

typedef enum s_token_type
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	int					i;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

typedef enum e_node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_CMD
}	t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND
}	t_io_type;

typedef enum e_parse_err_type
{
	E_MEM = 1,
	E_SYNTAX
}	t_parse_err_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}	t_io_node;

typedef struct s_node
{
	t_node_type			type;
	t_io_node			*io_list;
	char				*args;
	char				**expanded_args;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_parse_err
{
	t_parse_err_type	type;
	char				*str;
}	t_parse_err;

typedef struct s_minishell
{
	char			*line;
	t_token			*tokens;
	t_token			*curr_token;
	t_node			*ast;
	int				exit_s;
	bool			signint_child;
	t_parse_err		parse_err;
	int				stdin;
	int				stdout;
	char			**environ;
	t_env			*envlst;
	bool			heredoc_sigint;
	struct termios	original_term;
}					t_minishell;

#endif
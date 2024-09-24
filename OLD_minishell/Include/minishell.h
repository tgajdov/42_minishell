/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:21:47 by brferran          #+#    #+#             */
/*   Updated: 2024/06/11 16:39:36 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define HRDC_FILE "/tmp/.heredoc"
# define PIPE_FILE "/tmp/.pipex"

// Create with our hands
# include "../libft/libft.h"

// Standard libraries
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
/* trouver une solution pour remplacer mon nom ici par un $(whoami)
je n'arrive pas a ce que le makefile trouve le readline.h*/
// # include "/Users/tgajdov/.brew/opt/readline/include/readline/readline.h"
// # include "/Users/tgajdov/.brew/opt/readline/include/readline/history.h"
#include <readline/readline.h>
#include <readline/history.h>

# define DEBUG(str) printf("\033[91m%s, line:%d\033[39m\n%s\n\n", __FILE__, __LINE__, str);

typedef struct s_export
{
	char	**environ;
	char	**export_env;
	char	**way;
	char	*heredoc;
	char	*pipex;
	int		std[2];
	int		status;
	int		back;
	int		should_exit;
	int		access;
}	t_export;

typedef struct s_token
{
	char			*input;
	char			**argument;
	char			*cmd;
	char			*operator;
	char			*arg_operator;
	int				pipe;
	int				quotes;
	struct s_token	*next;
}	t_token;

//gat ft
char		*get_var(t_export *allotrack, char *var);
/* char	*ft_getcmdpath(char *cmd, char **envp);
void	ft_exceve(char *av, char **envp); */

// -- FIRSTPARSE --

// check.c
int			is_wildcard(char *str, t_token *token);
void		check_quotes(char c, t_token *token);
int			check_closedquotes(char *str, t_token *token);
int			is_echon(char *str, int i, t_token *token);

//get_arg.c
int			get_arg(char *str, int i, t_token *token);

// parsing_cmd.c
int			ft_strcasecmp(char *s1, char *s2, size_t i);
int			get_cmd(char *str, int i, t_token *token);
char		**ft_realloc2(char *new_arg, t_token *token);

//parsing_input_utils.c
char		*get_words(char *str, int i, char *delimiters);
char		*get_quotes(char *str, int i, t_token *token);
char		*get_symbols(char *str, int i);
int			is_space(char *str, int i);
char		*ft_strncpy(char *dest, const char *src, int n);

// parsing_input.c
t_token		*initialize_token(void);
t_token		*parsing_input(char *str);

// -- PARSING --

// convert_utils.c
char		*choose_convert(char *dollars, t_export *alloctrack);
char		*get_str_pid(void);
char		*dollars_lex(char *var_name, t_export *alloctrack);
char		*ft_strcat(char *dst, char *src);

// convert.c
char		*convert_n_concat(char **arg_more, t_export *alloctrack);

// new_arg_utils.c
char		**quote_parse(char *arg);

// new_arg.c
char		**replace_argument(char **argument, t_export *alloctrack);

// erase_quote.c
char		*erase_quote(char *s);

// parsing.c
int			check_wildcard(char *s);
char		**ft_parsing(char **argument, t_export *alloctrack);

// -- OPERATORS -- All Operators

int			is_directory(const char *path);
int			is_regular_file(const char *path);
// cmd_redirect.c
int			redirect_input(char *filename);
int			redirect_output(char *filename);

// pipe.c
int			ft_pipe(int fd[2], t_export *alloctrack);

// redirect_input_cmd.c
int			redirect_input_command(t_token *tokens, t_export *alloctrack);

// redirect_stdout.c
int			redirect_stdout_append(char *fichier);

int			check_for_next_redirect(t_token **token, t_export *alloctrack);

// -- CMD -- All commands

// cd.c
int			cd(char *path, t_export *alloctrack);

// echo.c
int			echo(char *input);
int			echon(char *input);

// env.c
int			ft_env(t_export *alloctrack, int n);

// exec.c
int			exec(char *exec, char **arg, char **env, t_export *alloctrack);

//exit.c
void		ft_exit(int num, t_export *alloctrack);

// export.c
int			ft_export(char *v_env, t_export *alloctrack);

// pwd.c
int			pwd(void);

// unset.c
int			ft_unset(char *var_name, t_export *alloctrack);

// value_return.c
char		*last_return(int status);

// way_utils.c
char		**check_if_good_way(char **way, char *cmd);
void		complete_way(char **way, char *cmd, char **tmp, int t);

// -- UTILS --

// initialisation.c
char		**ft_tabdup(char **env);
t_export	*init(char **env);

// error.c
int			error_zero(int num);
int			error_neg(int n);
char		*error_null(int n);
int			err_exit(int num);

// free.c
void		free_tab(char **entries);
void		free_alloctrack(t_export *alloctrack);
void		free_token_chain(t_token *token);

// utils.c
int			tablen(char **tab);
int			tab_slen(char **tab);
char		*ft_strstr(const char *s1, const char *s2);
int			search_occurence(char *str1, char *str2);

// -- LEXING -- 

// access_utils.c
char		**init_way_path(t_export *alloctrack);
char		**argument_system(t_token *tokens);
int			is_access(char **way, t_export *alloctrack);

// cmd_exec.c
int			make_exec(t_token *tokens, t_export *alloctrack);

// access.c
int			exec_system(t_token *tokens, t_export *alloctrack);

// operator.c
int			operators(t_token *tokens, t_export *alloctrack);

// cmd_utils.c
int			make_unset(t_token *tokens, t_export *alloctrack);
int			make_echo(t_token *tokens, t_export *alloctrack);
int			make_echon(t_token *tokens, t_export *alloctrack);
int			make_cd(t_token *tokens, t_export *alloctrack);
int			make_pwd(t_token *tokens, t_export *alloctrack);
int			make_export(t_token *tokens, t_export *alloctrack);

// cmd.c
int			cmd(t_token *tokens, t_export *alloctrack);

// cnf_utils.c
int			error_echo(char *cmd, t_export *alloctrack);
int			error_cd(char *cmd, t_export *alloctrack);
int			error_pwd(char *cmd, t_export *alloctrack);
int			error_export_unset_env(char *cmd, t_export *alloctrack);
int			error_exit(char *cmd, t_export *alloctrack);

//cnf.c
int			command_not_found(t_token *tokens, t_export *alloctrack);

// lexing.c
int			lexing(t_token *tokens, t_export *alloctrack);

// -- MINISHELL --

// take_input.c
char		*take_input(t_export *alloctrack);

// input_pipe.c
char		*input_pipe(char *input);

// signaux.c
void		signal_print_newline(int signal);
void		default_signals(void);
void		setup_signal(void);
void		restore_sigquit(void);
void		ignore_sigquit(void);

// mnsh_utils.c
t_token		*create_void_token(void);
void		save_std(int fd[2]);
void		redirect_std(int fd[2]);

// -- DEBUG --

// Mnsh/Debug.c
void		printer_tokens(t_token *tokens);
void		print_argument(char **argument);
void		print_tok(t_token *tokens);

#endif
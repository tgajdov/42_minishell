/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 17:47:20 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This is the main header of the minishell project.
 * It includes all the necessary headers to use the standard library,
 * the readline library and the sys/wait.h header.
 * It also includes the structures and functions used by the minishell.
 */
#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>
# include "colors.h"
# include "struct.h"
# include "../lib/includes/libft.h"

# define PROMPT "minis_hell > "
# define DEBUG(str) \
	printf(B_RED"%s, line: %d\n"B_BLACK, __FILE__, __LINE__); \
	printf("%s\n\n"C_RESET, str);

// builtin
// cd.c
int			builtin_cd(char *path);
// echo.c
int			builtin_echo(char **args);
// env_utils.c
bool		ft_env_entry_exists(char *key);
char		*ft_get_envlst_val(char *key);
void		ft_envlst_back(t_env *new);
void		ft_update_envlst(char *key, char *value, bool create);
// env.c
char		*ft_extract_key(char *str);
char		*ft_extract_value(char *str);
void		ft_init_envlst(void);
int			builtin_env(void);
// exit.c
void		builtin_exit(char **args);
// export.c
int			ft_check_key(char *str);
int			builtin_export(char **argv);
// pwd.c
int			builtin_pwd(void);
// unset.c
int			builtin_unset(char **args);

// clean
// ft_clean_empty_s.c
char		*ft_clean_empty_strs(char *str);
// ft_clean_ms.c
void		ft_clean_ms(void);
// panic.c
void		panic(char *str);

// execve
// check.c
t_err		ft_check_exec(char *file, bool cmd);
t_err		ft_check_read(char *file);
t_err		ft_check_write(char *file);
// error.c
int			ft_err_msg(t_err err);
// exec_builtin.c
int			ft_exec_builtin(char **args);
bool		ft_is_builtin(char *arg);
// exec_redirect.c
int			ft_append(t_io_node *io_list, int *status);
int			ft_in(t_io_node *io_list, int *status);
int			ft_out(t_io_node *io_list, int *status);
// exec_simple.c
void		ft_true_sigint_child(void);
int			ft_check_redirection(t_node *node);
void		ft_reset_stds(bool piped);
int			ft_exec_simple_cmd(t_node *node, bool piped);
// exec.c
void		ft_false_sigint_child(void);
int			ft_get_exit_status(int status);
int			ft_exec_node(t_node *tree, bool piped);
// get_path.c
t_path		ft_get_path(char *cmd);
// init_tree.c
void		ft_heredoc(t_io_node *io, int p[2]);
void		ft_init_tree(t_node *node);
// utils_execve.c
void		*ft_garbage_collector(void *ptr, bool clean);
bool		ft_is_delimiter(char *delimiter, char *str);

// more_lib
// ft_strcmp.c
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncasecmp(const char *s1, const char *s2, size_t n);

// signals
// signals.c
void		ft_sigquit_handler(int num);
void		ft_init_signals(void);

// utils
int			ft_fork(void);
char		*ft_getenv(const char *name, char **envp);
int			ft_print_tab(char **tab);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
t_minishell	*get_g_minishell(void);

#endif
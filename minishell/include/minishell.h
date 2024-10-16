/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:33:47 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define PROMPT "minishell > "
# define DEBUG(str) printf(B_RED"%s, line: %d\n"B_BLACK"%s\n\n"C_RESET, __FILE__, __LINE__, str);

// builtin
// cd.c
int		builtin_cd(char *path);
// echo.c
int		builtin_echo(char **args);
// env_utils.c
bool	ft_env_entry_exists(char *key);
char	*ft_get_envlst_val(char *key);
void	ft_envlst_back(t_env *new);
void	ft_update_envlst(char *key, char *value, bool create);
// env.c
char	*ft_extract_key(char *str);
char	*ft_extract_value(char *str);
void	ft_init_envlst(void);
int		builtin_env(void);
// exit.c
void	builtin_exit(char **args);
// export.c
int		ft_check_key(char *str);
int		builtin_export(char **argv);
// pwd.c
int		builtin_pwd(void);
// unset.c
int		builtin_unset(char **args);
// exec_builtin.c
int		ft_exec_builtin(char **args);
bool	ft_is_builtin(char *arg);


// clean
// ft_clean_ms.c
void	ft_clean_ms(void);


// execve
// execve_utils.c
void	*ft_garbage_collector(void *ptr, bool clean);
bool	ft_is_delimiter(char *delimiter, char *str);

// more_lib
// ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);

// safe_functions

// utils
char	*ft_getenv(const char *name, char **envp);
int		ft_print_tab(char **tab);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);


#endif
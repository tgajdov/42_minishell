/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/15 16:31:01 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <readline/readline.h>
# include <readline/history.h>
# include "colors.h"
# include "builtins.h"
# include "../lib/includes/libft.h"

# define PROMPT "minishell> "
# define DEBUG(str) printf(B_RED"%s, line: %d\n"B_BLACK"%s\n\n"C_RESET, __FILE__, __LINE__, str);

typedef enum e_builtin_code
{
	CD,
	ENV,
	ECHON,
	ECHO,
	EXPORT,
	EXIT,
	PWD,
	UNSET
}		t_builtin_code;

typedef struct s_command_table {

	int		ac;
	char	**av;
	char	**envp;
	
	char	*cmd;
	char	*cmd_path;

	int		exit_status;	
}			t_command_table;

// builtin
int		builtin_cd(char *cmd_str);
int		builtin_echo(char *str, t_builtin_code code);
int		builtin_env(char **envp);
void	builtin_exit(char **args);
void	builtin_export(char **args, char **envp);
int		builtin_pwd(char **envp);
void	builtin_unset(char **args, char **envp);
int		ft_env_len(char **env);
int		is_valid_identifier(const char *str);

// errors
void	error_exit(const char *error/* , t_data *name_struct */);

// execve
void	ft_exceve(char *cmd_str, char **envp);
char	*ft_getcmdpath(char *cmd, char **envp);

// safe_functions

// utils
char	*ft_getenv(const char *name, char **envp);
int	ft_print_tab(char **tab);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);


#endif
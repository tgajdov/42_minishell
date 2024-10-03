/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 12:30:09 by tgajdov          ###   ########.fr       */
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
# include "../libft/includes/libft.h"

# define PROMPT "minishell> "
# define DEBUG(str) printf(B_RED"%s, line: %d\n"B_BLACK"%s\n\n"C_RESET, __FILE__, __LINE__, str);

typedef struct s_data {

	int		ac;
	char	**av;
	char	**envp;
	
	char	*cmd;
	char	*cmd_path;

	int		exit_status;	
}			t_data;

char	*ft_getcmdpath(char *cmd, char **envp);
void	ft_exceve(int ac, char **av, char **envp);


void	error_exit(const char *error/* , t_data *name_struct */);

#endif
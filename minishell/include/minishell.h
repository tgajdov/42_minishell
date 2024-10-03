/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:08:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 08:04:10 by tgajdov          ###   ########.fr       */
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

# define DEBUG(str) printf(B_RED"%s, line: %d\n"B_BLACK"%s\n\n"C_RESET, __FILE__, __LINE__, str);

typedef struct s_data {

	int		ac;
	char	**av;
	char	**envp;
	
	char	*cmd;
	char	*cmd_path;
	
}			t_data;

#endif
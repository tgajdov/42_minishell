/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:26:06 by tgajdov           #+#    #+#             */
/*   Updated: 2024/02/19 18:26:18 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "Libft/libft.h"

//ici void ft();
char	*ft_getpwd(char **envp);
int		ft_check_entry(int ac, char **av);
char	*ft_getcmdpath(char *cmd, char **envp);
void	ft_exceve(int ac, char **argv, char **envp);
void	ft_exit(char *str);

#endif

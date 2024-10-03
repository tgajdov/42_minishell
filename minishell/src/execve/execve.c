/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:05:08 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/02 08:05:57 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exceve(int ac, char **av, char **envp)
{
	char	*thepath;
	char	**thecmd;

	thecmd = ft_split(av[ac], ' ');
	thepath = ft_getcmdpath(thecmd[0], envp);
	if (execve(thepath, thecmd, envp) == -1)
		ft_exit("Could not find programm to execute");
}
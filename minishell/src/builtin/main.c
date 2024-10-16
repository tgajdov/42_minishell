/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:41:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 15:58:05 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_minishell	g_minishell;

static void	*ft_init_minishell(char **env)
{
	ft_memset(&g_minishell, 0, sizeof(t_minishell));
	g_minishell.environ = env;
	ft_init_envlst();
	// g_minishell.stdin = dup(0);
	// g_minishell.stdout = dup(1);
	//tcgetattr(STDIN_FILENO, &minishell.original_term);
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	char *cmd_str = {"cd bla"};

	ft_init_minishell(envp);
	if (!ac && !av)
		return (0);
	if (ft_is_builtin(cmd_str))
		ft_exec_builtin(&cmd_str);
	else
	{
		printf("Wrong arguments\n");
		exit(1);
	}
	return (0);
}
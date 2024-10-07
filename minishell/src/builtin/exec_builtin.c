/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/07 16:38:31 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

typedef enum e_builtin_code
{
	CD,
	ENV,
	ECHO,
	EXPORT,
	EXIT,
	PWD,
	UNSET
}		t_builtin_code;

t_builtin_code	look_for_builtin(char *cmd_str)
{
	const char *builtin_tab[] = {
		"cd",
		"env",
		"echo",
		"export",
		"exit",
		"pwd",
		"unset"
	};
	//Faut voir comment arranger ça

	int		i;
	char	**cmd_tab;

	i = 0;
	if (!cmd_str)
		return (0);
	cmd_tab = ft_split(cmd_str, ' ');
	// Comment free cmd_tab?
	
	//faut-il securiser du genre
	// if(!cmd_tab)
	// 	return();
	while (i < 7)
	{
		if (ft_strncasecmp(cmd_tab[0], builtin_tab[i], ft_strlen(cmd_tab[0])) == 0)
		{
			printf("The results : %s\n", builtin_tab[i]);
			return (i);
		}
		i++;
	}
	ft_free_tab(cmd_tab);
	printf("No match\n");
	return (NULL);
}

void execute_builtin(t_builtin_code code)
{
	// if (code == CD)
	// 	builtin_cd(cmd_tab, envp);
	// else if (code == ENV)
	// 	builtin_env(envp);
	// else if (code == ECHO)
	// 	builtin_echo(cmd_tab, envp);
	// else if (code == EXPORT)
	// 	builtin_export(cmd_tab, envp);
	// else if (code == EXIT)
	// 	builtin_exit(cmd_tab, envp);
	if (code == PWD)
		builtin_pwd();
	// else if (code == UNSET)
	// 	builtin_unset(cmd_tab, envp);
	else
		printf("No match\n");
}

int	main(void)
{
	char *argv = {"pwd"};

	if (argv)
		execute_builtin(look_for_builtin(argv)) ;
	else
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	return (0);
}


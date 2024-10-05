/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/05 21:08:06 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

/* t_command builtin_tab[8] = {

	{"cd", 100},
	{"env", 101},
	{"echo", 102},
	{"export", 103},
	{"exit", 104},
	{"pwd", 105},
	{"unset", 106},
	{NULL, 0}

	{"cd", &builtin_cd},
	{"env", &builtin_env},
	{"echo", &builtin_echo},
	{"export", &builtin_export},
	{"exit", &builtin_exit},
	{"pwd", &builtin_pwd},
	{"unset", &builtin_unset},
	{NULL, NULL}
} ; */

char	*look_for_builtin(char *cmd_str)
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
		if (ft_strncmp(cmd_tab[0], builtin_tab[i], ft_strlen(cmd_tab[0])) == 0)
		{
			printf("The results : %s\n", builtin_tab[i]);
			return (cmd_tab[0]);
		}
		i++;
	}
	ft_free_tab(cmd_tab);
	printf("No match\n");
	return (NULL);
}



int	main(void)
{
	char *argv = {"cdd HELLO=123 A-"};

	if (argv)
		look_for_builtin(argv);
	else
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	return (0);
}


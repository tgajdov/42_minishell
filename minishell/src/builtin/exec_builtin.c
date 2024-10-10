/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:18 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/10 17:57:22 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

t_builtin_code	look_for_builtin(char *cmd_str)
{
	const char *builtin_tab[] = {
		"cd",
		"env",
		"echo -n",
		"echo",
		"export",
		"exit",
		"pwd",
		"unset"
	};
	//Faut voir comment arranger ça

	int		cmd_pos;
	char	**cmd_tab;

	cmd_pos = 0;
	if (!cmd_str)
		return (0);
	cmd_tab = ft_split(cmd_str, ' ');	
	if(!cmd_tab)
	/*definir un code d'erreur si aucune correspondance*/
		return(42);
	while (cmd_pos < 8)
	{
		if (ft_strncasecmp(cmd_tab[0], builtin_tab[cmd_pos], ft_strlen(builtin_tab[cmd_pos])) == 0)
		{
			printf("The results : %s, and his position : %d\n", builtin_tab[cmd_pos], cmd_pos);
			ft_free_tab(cmd_tab);
			return (cmd_pos);
		}
		cmd_pos++;
	}
	ft_free_tab(cmd_tab);
	printf("No match in look_for_builtin\n");
	/*definir un code d'erreur si aucune correspondance*/
	return (42);
}

void	execute_builtin(t_builtin_code code, char *cmd_str, char **envp)
{
	if (code == 42)
		return ;
	else if (code == CD)
		builtin_cd(cmd_str);
	else if (code == ENV)
		builtin_env(envp);
	else if (code == ECHO || code == ECHON)
		builtin_echo(cmd_str, code);
	// else if (code == EXPORT)
	// 	builtin_export(cmd_tab, envp);
	// else if (code == EXIT)
	// 	builtin_exit(cmd_tab, envp);
	else if (code == PWD)
		builtin_pwd();
	// else if (code == UNSET)
	// 	builtin_unset(cmd_tab, envp);
	else
		printf("No match in execute_builtin\n");
}

int	main(int ac, char **av, char **envp)
{
	char *cmd_str = {"cd"};
	/* envlever les espaces en trop entre les arguments
	*/

	if (!ac && !av)
		return (0);
	if (cmd_str)
		execute_builtin(look_for_builtin(cmd_str), cmd_str, envp);
	else
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:16:46 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 13:00:59 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Outputs an error message if the identifier passed to the export
 *        function is not a valid identifier.
 *
 * This function outputs "minishell: export: `<identifier>': not a valid
 * identifier\n" to stderr if the identifier passed to the export function
 * is not a valid identifier.
 *
 * @param identifier The identifier passed to the export function.
 * @return 1 to indicate that an error occurred.
 */
static int	ft_export_err_msg(char *identifier)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(identifier, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

/**
 * @brief Outputs the current environment variables to stdout in a format
 *        compatible with Bash.
 *
 * This function outputs the environment variables in the format
 * "declare -x <key>=\"<value>\"", where <key> is the name of the variable
 * and <value> is the value of the variable. If the variable's value is
 * NULL, the output is "declare -x <key>".
 *
 * This function is used by the export command when no arguments are provided.
 */
static	void	ft_export_list(void)
{
	t_minishell	*g_minishell;
	t_env		*list;
	size_t		i;

	g_minishell = get_g_minishell();
	list = g_minishell->envlst;
	while (list)
	{
		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
		{
			printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					printf("\\%c", (list->value)[i++]);
				else
					printf("%c", (list->value)[i++]);
			}
			printf("\"\n");
		}
		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
			printf("declare -x %s\n", list->key);
		list = list->next;
	}
}

/**
 * @brief Checks if a string can be used as an environment variable key.
 *
 * A valid environment variable key must start with a letter or an underscore,
 * and the rest of the characters must be alphanumeric or underscores.
 *
 * This function returns 1 if the string is valid, and 0 otherwise.
 */
int	ft_check_key(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Handles the export command.
 *
 * The export command takes a list of variables to update or create in the
 * environment. If no arguments are provided, the export command outputs the
 * current environment variables to stdout in a format compatible with Bash.
 *
 * This function returns the exit status of the export command.
 */
int	builtin_export(char **argv)
{
	int		i;
	int		exit_s;
	char	*key;

	exit_s = 0;
	i = 1;
	if (!argv[1])
		return (ft_export_list(), 0);
	while (argv[i])
	{
		if (ft_check_key(argv[i]) == 0)
			exit_s = ft_export_err_msg(argv[i]);
		else
		{
			key = ft_extract_key(argv[i]);
			if (ft_env_entry_exists(key))
				ft_update_envlst(key, ft_extract_value(argv[i]), false);
			else
				ft_update_envlst(key, ft_extract_value(argv[i]), true);
		}
		i++;
	}
	return (exit_s);
}

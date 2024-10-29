/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:25 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 12:52:53 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Updates the "PWD" variable in the environment list.
 * This function calls getcwd to get the current working directory,
 * and then calls ft_update_envlst to update the "PWD" variable in the
 * environment list.
 *
 * @return 0 if the function is successful, 1 otherwise.
 */
static int	ft_change_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	return (ft_update_envlst("PWD", cwd, false), 0);
}

/**
 * @brief Changes the current directory to the user's HOME directory.
 *
 * This function updates the "OLDPWD" environment variable with the current 
 * "PWD" value, retrieves the "HOME" environment variable, and attempts to 
 * change the current directory to the HOME directory. If the "HOME" 
 * environment variable is not set, it outputs an error message. If the 
 * directory change is successful, it updates the "PWD" environment 
 * variable with the new directory path.
 *
 * @return 0 if the directory change is successful, 1 if "HOME" is not set 
 * or the directory change fails.
 */
static int	ft_cd_home(void)
{
	char	*home;

	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	home = ft_get_envlst_val("HOME");
	if (!home)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	if (chdir(home) == ENO_SUCCESS)
		return (ft_update_envlst("PWD", home, false), 0);
	return (1);
}

/**
 * @brief Outputs an error message if the directory change fails.
 *
 * This function outputs "minishell: cd: <err_msg>: <strerror(errno)>\n" to 
 * stderr if the directory change fails.
 *
 * @param err_msg The parameter passed to the cd function.
 * @return 1 to indicate that an error occurred.
 */
static int	ft_cd_err_msg(char *err_msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

/**
 * @brief Changes the current directory.
 *
 * This function changes the current directory to the one given in the 
 * parameter. If the parameter is NULL, it changes the current directory to 
 * the HOME directory. If the directory change fails, it outputs an error 
 * message. If the directory change is successful, it updates the "OLDPWD" 
 * and "PWD" environment variables with the old and new directory paths 
 * respectively.
 *
 * @param path The path to the directory to change to.
 * @return 0 if the directory change is successful, 1 if it fails.
 */
int	builtin_cd(char *path)
{
	if (!path)
		return (ft_cd_home());
	if (chdir(path) != ENO_SUCCESS)
		return (ft_cd_err_msg(path));
	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	return (ft_change_pwd());
}

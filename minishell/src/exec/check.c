/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:30:20 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/29 14:07:12 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Checks if a file exists and can be executed.
 *
 * @param file The file to check.
 * @param cmd Whether to check for a command or a regular file.
 *
 * @return A t_err struct containing the error code, message, and cause.
 *
 * The function checks if the file exists. If it does, it checks if it is
 * a directory. If it is not a directory, it checks if the file can be
 * executed. If the file can be executed, the function returns a t_err
 * struct with error code ENO_SUCCESS, message 42, and cause NULL.
 * If the file cannot be executed, the function returns a t_err struct
 * with error code ENO_CANT_EXEC, message ERRMSG_PERM_DENIED, and cause
 * the file name.
 * If the file does not exist and cmd is true, the function returns a t_err
 * struct with error code ENO_NOT_FOUND, message ERRMSG_CMD_NOT_FOUND, and
 * cause the file name.
 * If the file does not exist and cmd is false, the function returns a t_err
 * struct with error code ENO_NOT_FOUND, message ERRMSG_NO_SUCH_FILE, and
 * cause the file name.
 */
t_err	ft_check_exec(char *file, bool cmd)
{
	struct stat	file_stat;

	if (!*file)
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (stat(file, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
			return ((t_err){ENO_CANT_EXEC, ERRMSG_FILEISDIR, file});
		if (access(file, X_OK) == -1)
			return ((t_err){ENO_CANT_EXEC, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	if (cmd)
		return ((t_err){ENO_NOT_FOUND, ERRMSG_CMD_NOT_FOUND, file});
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}

/**
 * @brief Checks if a file exists and can be read.
 *
 * @param file The file to check.
 *
 * @return A t_err struct containing the error code, message, and cause.
 *
 * The function checks if the file exists. If it does, it checks if the file
 * can be read. If the file can be read, the function returns a t_err struct
 * with error code ENO_SUCCESS, message 42, and cause NULL.
 * If the file cannot be read, the function returns a t_err struct with error
 * code ENO_GENERAL, message ERRMSG_PERM_DENIED, and cause the file name.
 * If the file does not exist, the function returns a t_err struct with error
 * code ENO_NOT_FOUND, message ERRMSG_NO_SUCH_FILE, and cause the file name.
 */
t_err	ft_check_read(char *file)
{
	if (!*file)
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) == -1)
			return ((t_err){ENO_GENERAL, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}

/**
 * @brief Checks if a file exists and can be written to.
 *
 * @param file The file to check.
 *
 * @return A t_err struct containing the error code, message, and cause.
 *
 * The function checks if the file exists. If it does, it checks if the file
 * can be written to. If the file can be written to, the function returns
 * a t_err struct with error code ENO_SUCCESS, message 42, and cause NULL.
 * If the file cannot be written to, the function returns a t_err struct
 * with error code ENO_GENERAL, message ERRMSG_PERM_DENIED, and cause the
 * file name. If the file does not exist, the function returns a t_err
 * struct with error code ENO_NOT_FOUND, message ERRMSG_NO_SUCH_FILE, and
 * cause the file name.
 */
t_err	ft_check_write(char *file)
{
	if (!*file)
		return ((t_err){ENO_GENERAL, ERRMSG_NO_SUCH_FILE, file});
	if (access(file, F_OK) == 0)
	{
		if (access(file, W_OK) == -1)
			return ((t_err){ENO_GENERAL, ERRMSG_PERM_DENIED, file});
		return ((t_err){ENO_SUCCESS, 42, NULL});
	}
	return ((t_err){ENO_NOT_FOUND, ERRMSG_NO_SUCH_FILE, file});
}

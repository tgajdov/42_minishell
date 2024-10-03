/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:49 by tgajdov           #+#    #+#             */
/*   Updated: 2023/11/18 14:17:57 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*read_line(int fd, char *saved_line, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (0);
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!saved_line)
			saved_line = ft_strdup("");
		if (!saved_line)
			return (0);
		tmp = saved_line;
		saved_line = ft_strjoin(tmp, buffer);
		if (!saved_line)
			return (0);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (saved_line);
}

static char	*clear_line(char *ret_line)
{
	char	*saved_line;
	ssize_t	i;

	i = 0;
	while (ret_line[i] != '\n' && ret_line[i] != '\0')
		i++;
	if (ret_line[i] == 0 || ret_line[1] == 0)
		return (0);
	saved_line = ft_substr(ret_line, i + 1, ft_strlen(ret_line) - i);
	if (*saved_line == 0)
	{
		free(saved_line);
		saved_line = 0;
	}
	ret_line[i + 1] = 0;
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*ret_line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
	{
		free(saved_line);
		free(buffer);
		saved_line = 0;
		return (0);
	}
	if (!buffer)
		return (0);
	ret_line = read_line(fd, saved_line, buffer);
	if (!ret_line || fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	if (!ret_line)
		return (0);
	saved_line = clear_line(ret_line);
	return (ret_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:41 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:30:06 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define RED       "\x1b[31m"
#define ANSI_COLOR_WHITE     "\x1b[37m"
#define ANSI_COLOR_RESET      "\x1b[0m"

static char	*ft_getcwd(void)
{
	char	*result;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	result = ft_strrchr(tmp, '/');
	free(tmp);
	return (result);
}

static char	*getprompt(void)
{
	char	*s1;
	char	*pwd;
	char	*concat;
	int		i;
	int		c;

	s1 = RED "[m" ANSI_COLOR_WHITE "ns" RED "h]" ANSI_COLOR_RESET;
	pwd = ft_getcwd();
	concat = malloc((ft_strlen(s1) + ft_strlen(pwd) + 4) * sizeof (char));
	i = 0;
	c = 0;
	while (s1[i])
		concat[c++] = s1[i++];
	concat[c++] = '/';
	i = 0;
	while (pwd[i])
		concat[c++] = pwd[i++];
	concat[c++] = ' ';
	concat[c++] = ':';
	concat[c++] = ' ';
	concat[c] = '\0';
	return (concat);
}

char	*take_input(t_export *alloctrack)
{
	char	*input;
	char	*prompt;
	int		take;

	take = 0;
	while (take == 0)
	{
		prompt = getprompt();
		input = readline(prompt);
		if (input)
		{
			if (input[0] == '\0')
				return (NULL);
			if (input[0] != '\0')
				add_history(input);
			take = 1;
		}
		if (input == NULL)
		{
			free(prompt);
			ft_exit(-42, alloctrack);
		}
		free(prompt);
	}
	return (input);
}

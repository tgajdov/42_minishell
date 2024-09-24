/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:28 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:26:05 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	first_pipe(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
	{
		printf("mnsh : parse error near '|'\n");
		free(input);
		return (0);
	}
	return (1);
}

static char	*ft_freed(char *input)
{
	char	*tmp;

	if (input)
		free(input);
	tmp = ft_strdup("");
	return (tmp);
}

static char	*take_input_again(char *input)
{
	char	*input_more;
	char	*new_input;
	int		more;

	more = 0;
	while (more == 0)
	{
		input_more = readline("> ");
		add_history(input_more);
		if (input_more)
		{
			if (!first_pipe(input_more))
				return (NULL);
			more = 1;
		}
		if (input_more == NULL)
			return (ft_freed(input));
	}
	new_input = ft_strcat(input, input_more);
	free(input);
	free(input_more);
	return (new_input);
}

char	*input_pipe(char *input)
{
	int	i;

	if (!input)
		return (NULL);
	while (1)
	{
		if (!first_pipe(input))
			return (NULL);
		i = ft_strlen(input) - 1;
		while (input[i] == ' ')
			i--;
		if (input[i] == '|')
		{
			input = take_input_again(input);
			if (!input || (input && input[0] == '\0'))
				return (input);
		}
		else
			break ;
	}
	return (input);
}

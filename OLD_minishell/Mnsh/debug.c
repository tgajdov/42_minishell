/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brferran <brferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:00 by brferran          #+#    #+#             */
/*   Updated: 2024/05/21 15:22:28 by brferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void printer_tokens(t_token *tokens)
{
    int i;

    if (tokens)
    {
        while (tokens)
        {
            printf("Pipe is : %d\n", tokens->pipe);
            printf("Input is : %s\n", tokens->input);
            if (tokens->argument)
            {
                i = 0;
                while (tokens->argument[i])
                {
                    printf ("Argument[%d] is : %s\n", i, tokens->argument[i]);
                    i++;
                }
                printf ("Argument[%d] is : %s\n", i, tokens->argument[i]);
            }
            printf("Cmd is : %s\n", tokens->cmd);
            printf("Operator is : %s\n", tokens->operator);
            printf("Arg_opérator is : %s\n", tokens->arg_operator);
            if (!tokens->next)
                printf("-- LAST TOKEN --\n");
            else
                printf("-- NEXT TOKEN --\n");
            tokens = tokens->next;
        }
    }
}

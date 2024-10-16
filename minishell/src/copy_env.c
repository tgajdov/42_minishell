/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:57:43 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/16 16:12:17 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* 
* La fonction copy_env permet de copier le tableau de string
* point  par envp qui contient les variables d'environnement.
* On procede en premier lieu en comptant le nombre de string
* contenus dans envp, puis en allouant de la memoire pour
* le nouveau tableau de string. Ensuite, on copie chaque string
* de envp dans le nouveau tableau en utilisant ft_strdup.
* On termine en ajoutant un pointeur nul a la fin du tableau.
*
*
* Reste à voir comment porteger l'allocation de mémoire
* comment free en cas d'échec de l'allocation.
*/

/* char	**copy_env(char **envp)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = 0;
	return (new_envp);
} */

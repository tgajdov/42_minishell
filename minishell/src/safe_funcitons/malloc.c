/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:22:41 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/03 12:29:54 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	*safe_malloc(size_t bytes/* , t_data *name_struct */) //créer notre struct, si besoin! Exemple pour gestion erreur sinon peut être enlevé
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		exit(1);

	/* if (NULL == ret)
		error_exit("Error with malloc", name_struct); //créer error_exit et adapter en fonction
	 */
	return (ret);
}

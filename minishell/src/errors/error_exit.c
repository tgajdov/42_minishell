/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgajdov <tgajdov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:10:28 by tgajdov           #+#    #+#             */
/*   Updated: 2024/10/01 15:10:44 by tgajdov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	error_exit(const char *error, t_struct *name_struct) //créer notre struct, si besoin! Exemple pour gestion erreur sinon peut être enlevé
{
	printf(B_RED"%s\n"C_RESET, error);

	//set_bool(&table->table_mutex, &table->end_simulation, true, table);
	//ou bien
	//exit();
}
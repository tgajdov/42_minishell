#include"minishell.h"

void	error_exit(const char *error, t_struct *name_struct) //créer notre struct, si besoin! Exemple pour gestion erreur sinon peut être enlevé
{
	printf(B_RED"%s\n"C_RESET, error);

	//set_bool(&table->table_mutex, &table->end_simulation, true, table);
	//ou bien
	//exit();
}
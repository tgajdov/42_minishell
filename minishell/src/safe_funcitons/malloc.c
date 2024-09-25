#include "minishell.h"

void	*safe_malloc(size_t bytes, t_struct *name_struct) //créer notre struct, si besoin! Exemple pour gestion erreur sinon peut être enlevé
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		error_exit("Error with malloc", name_struct); //créer error_exit et adapter en fonction
	return (ret);
}

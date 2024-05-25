#include "minishell.h"

char*	get_var(t_export *allotrack, char *var)
{
	int	i;

	i = 0;
	while(strnstr(allotrack->environ[i], var, ft_strlen(var)) == 0)
		i++;
	return (allotrack->environ[i] + ft_strlen(var) + 1);
}
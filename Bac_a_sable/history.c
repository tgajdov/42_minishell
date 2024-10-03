#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
	char *input;
	int i;
	
	i = 0;
	while ((input = readline("Minishell : ")) != NULL)
	{
		if (*input) // Vérifie si la chaîne n'est pas vide
			//add_history(input); // Traiter la commande
		if (i % 5 == 0)
			clear_history();
		free(input); // Libérer la mémoire allouée par readline
		i++;
	}
	return 0;
}
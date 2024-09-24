#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void execute_command(char *cmd)
{
    if (ft_strncmp(cmd, "cd", 2) == 0) {
        chdir(cmd + 3);  // Très simplifié, sans gestion des erreurs
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            execlp(cmd, cmd, (char *)NULL);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }
}

int main(void)
{
    char *input;

    while ((input = readline("minishell> ")) != NULL) {
        if (ft_strlen(input) > 0)
            add_history(input);
        execute_command(input);
        free(input);
    }
    return 0;
}
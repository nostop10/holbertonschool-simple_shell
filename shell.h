#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/* Function to process user input */
void process_input() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    char *token;
    int status;

    while (1) {
        printf("$ ");
        fflush(stdout);

        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        // Tokenizing user input
        token = strtok(input, " \n");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // Creating a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror(args[0]); // In case command execution fails
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    process_input();
    return 0;
}


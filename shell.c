#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * Function to handle user input
 */
void handle_input(char *buffer) {
    if (isatty(STDIN_FILENO))
        printf("$ ");
    fflush(stdout);
    fgets(buffer, BUFFER_SIZE, stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
}

/**
 * Function to execute built-in commands
 */
int execute_builtin(char **args, char *buffer) {
    if (strcmp(args[0], "exit") == 0) {
        free(buffer);
        exit(0);
    }
    // Add more built-in commands here as needed
    return 0;  // Indicate command not handled as built-in
}

/**
 * Function to execute external commands
 */
void execute_external(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror(args[0]);
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

/**
 * Main function
 */
int main(void) {
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    char *args[BUFFER_SIZE];
    char *token;
    int argc;

    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    while (1) {
        // Handle user input
        handle_input(buffer);

        // Tokenize input
        token = strtok(buffer, " ");
        argc = 0;
        while (token != NULL) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        // Execute built-in commands
        if (execute_builtin(args, buffer))
            continue;

        // Execute external commands
        execute_external(args);
    }

    // Free allocated memory
    free(buffer);
    return 0;
}


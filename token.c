#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

char **tokenizer(char *input, char *delimiter) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(input, delimiter);
    int token_count = 0;
    while (token != NULL) {
        tokens[token_count] = strdup(token);
        if (tokens[token_count] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        token_count++;
        token = strtok(NULL, delimiter);
    }
    tokens[token_count] = NULL;

    return tokens;
}

int main() {
    char input[] = "This is a sample string";
    char *delimiter = " ";

    char **tokens = tokenizer(input, delimiter);

    int i = 0;
    while (tokens[i] != NULL) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]); // Free memory allocated by strdup
        i++;
    }
    free(tokens); // Free memory allocated for tokens array

    return 0;
}


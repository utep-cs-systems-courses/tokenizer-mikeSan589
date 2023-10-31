#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
    return c == ' ' || c == '\t';
}

int non_space_char(char c) {
    return c != ' ' && c != '\t' && c != '\0';
}

char *token_start(char *str) {
    while (space_char(*str)) str++;
    return *str == '\0' ? NULL : str;
}

char *token_terminator(char *token) {
    while (non_space_char(*token)) token++;
    return token;
}

int count_tokens(char *str) {
    char *start = str;
    int count = 0;
    while (*str != '\0') {
        str = token_start(str);
        if (str == NULL) break;

        str = token_terminator(str);
        count++;
    }
    str = start;
    return count;
}

char *copy_str(char *inStr, short len) {
    char *copy = malloc((len + 1) * sizeof(char));
    if (copy == NULL) {
        return NULL;
    }
    
    for (short i = 0; i < len; i++) {
        copy[i] = inStr[i];
    }
    copy[len] = '\0';
    return copy;
}

char **tokenize(char *str) {
    int token_count = count_tokens(str);
    char **tokens = malloc((token_count + 1) * sizeof(char *));
    
    int index = 0;
    while (index < token_count) {
        str = token_start(str);
        char *end = token_terminator(str);
        tokens[index] = copy_str(str, end - str);
        str = end;
        index++;
    }
    tokens[token_count] = NULL;
    return tokens;
}

void print_tokens(char **tokens) {
    if (tokens == NULL) {
        return;
    }
    
    int i = 0;
    while (tokens[i] != NULL) {
        printf("%s\n", tokens[i]);
        i++;
    }
}

void free_tokens(char **tokens) {
    if (tokens == NULL) {
        return;
    }
    
    int i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

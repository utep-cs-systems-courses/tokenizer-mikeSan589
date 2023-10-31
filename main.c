#include <stdio.h>
#include <string.h>
#include "tokenizer.h"   
#include "history.h"

int main() {
    char input[1000]; 
    char **tokens;

    
    List *history = init_history();

    printf("Welcome to the tokenizer!\n");
    printf("Instructions:\n");
    printf("- Type any phrase and press enter to tokenize it.\n");
    printf("- Type 'history' to see your input history.\n");
    printf("- Type 'exit' to quit the program.\n");

    while (1) {
        printf("\nPlease enter a phrase: ");
        fgets(input, 1000, stdin); 
        input[strlen(input)-1] = '\0'; 

       
        if (strcmp(input, "exit") == 0) {
            printf("Exiting. Goodbye!\n");
            free_history(history);
            return 0;
        }

      
        if (strcmp(input, "history") == 0) {
            print_history(history);
            continue;
        }

      
        tokens = tokenize(input); 

        
        add_history(history, input);

        
        printf("\nYour phrase tokenized:\n");
        print_tokens(tokens); 

       
        free_tokens(tokens);
    }

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/stack.h"
#include "include/tokens.h"

void process_tokens(char *tokens);

void change_decimal();

int precision = 2;
char format[16];

int main(void){
    char input[100]; 

    change_decimal();

    while(fgets(input, sizeof(input), stdin) != NULL && strcmp(input, "q\n") != 0){
        
        if(strncmp(input, "decimal ", 8) == 0){
            int new_precision;
            if (sscanf(input + 8, "%d", &new_precision) == 1) {
                if(new_precision < 0){
                    printf("Nova precisão inválida.\n");
                    continue;
                }
                precision = new_precision;
                printf("Precisão alterada para: %d\n", precision);
                change_decimal();
                continue; // pula para próxima iteração do loop
            }
            printf("Nova precisão inválida.\n");
            continue;
        }

        process_tokens(input);
        printf(format, pop());
    }

    printf("Bye!\n");
    return 0;
}

void change_decimal(){
    sprintf(format, "= %%.%df\n", precision);
}
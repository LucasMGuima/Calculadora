#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/stack.h"
#include "include/operations.h"

typedef struct {
    char * signal;
    float (*operation_func)(float, float);
} OPERATION;

void process_tokens(char *tokens);
int get_num();

OPERATION operations[] = {
    {"+", sum},
    {"-", sub},
    {"*", mult},
    {"/", divi},
    {"root", root},
    {"^", power}
};

int main(void){
    char input[100];

    fgets(input, sizeof(input), stdin);
    process_tokens(input);
    
    printf("Resultado: %f\n", pop());
    return 0;
}

void process_tokens(char *tokens){
    char * token = strtok(tokens, " \n");
    while (token != NULL){
        if(token[0] >= '0' && token[0] <= '9'){
            /* -- Identifica um número --*/
            int num = atoi(token);
            printf("> %d\n", num);
            push(num);
        }else if(token[0] == '-' && token[1] >= '0' && token[1] <= '9'){
            /* -- Verifica por número negativo --*/
            int num = atoi(token);
            printf("> %d\n", num);
            push(num);
        }else{
            /* -- Identifica uma operação --*/
            float num2 = get_num();
            float num1 = get_num();
            
            for(int i = 0; i < sizeof(operations); i++){
                if(strcmp(operations[i].signal, token) == 0){
                    float result = operations[i].operation_func(num1, num2);
                    push(result);
                    break;
                }
            }

        }
        token = strtok(NULL, " \n");
    }
}

int get_num(){
    if(is_empty()){
        printf("Número de elementos invalidos.\n");
        exit(0);
    }else{
        return pop();
    }
}
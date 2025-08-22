#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "include/operations.h"
#include "include/stack.h"

typedef struct {
    char * signal;
    float (*operation_func)(float, float);
} OPERATION;

float convert_num(char * str);
float get_num();

OPERATION operations[] = {
    {"+", sum},
    {"-", sub},
    {"*", mult},
    {"/", divi},
    {"root", root},
    {"^", power}
};

void process_tokens(char *tokens){
    char * token = strtok(tokens, " \n");
    while (token != NULL){
        if(token[0] >= '0' && token[0] <= '9'){
            /* -- Identifica um número --*/
            float num = convert_num(token);
            push(num);
        }else if(token[0] == '-' && token[1] >= '0' && token[1] <= '9'){
            /* -- Verifica por número negativo --*/
            float num = convert_num(token);
            push(num);
        }else{
            /* -- Identifica uma operação --*/
            float num2 = get_num();
            float num1 = get_num();
            
            for(size_t i = 0; i < sizeof(operations); i++){
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

float convert_num(char * str){
    /* Checa se valor tem ',' */
    /* Se existir altera para '.' */
    char *p = strchr(str, ',');
    if(p) *p = '.';
    
    /* Tenta converter o valor */
    int er_num = 0;
    float result = strtof(str, NULL);
    if(er_num == ERANGE){
        printf("O valor é muito grande/pequeno.\n");
        exit(12);
    }else{
        return result;
    }
}

float get_num(){
    if(is_empty()){
        printf("Número de elementos invalidos.\n");
        exit(1);
    }else{
        return pop();
    }
}
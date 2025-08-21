#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE float
#define STACK_SIZE 100

/*
    Retorna o marcador da pilha para a primeira
    posição da fila.
*/
void make_empty(void);
/*
    Verifica se a pilha está vazia.
    Retorna 1 se for verdade.
    0 se não.
*/
int is_empty(void);
/*
    Verifica se a pilha está cheia.
    Retorna 1 se for verdade.
    0 se não.
*/
int is_full(void);
/*
    Adiciona uma novo elemento a pilha.
*/
void push(STACK_TYPE i);
/*
    Remove um elemento da pilha.
*/
STACK_TYPE pop(void);

#endif /* _STACK_H_ */
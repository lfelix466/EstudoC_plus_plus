#include <stdio.h>
#include <stdlib.h>

// Definir a estrutura do nó da fila
typedef struct No {
    int data;
    struct No* proximo;
} No;

// Definir a estrutura da fila
typedef struct Fila {
    No* proximo;
    No* anterior;
} Fila;

Fila* criaFila(){
    /*Cria a fila*/

    Fila* fila = (Fila*)malloc(sizeof(Fila));
    
    if (!fila) {
        printf("Falha ao alocar memoria\n");
        exit(1);
    }

    fila->proximo = NULL;
    fila->anterior = NULL;
    return fila;
}

void populaFila(Fila* fila, int dado){
    /*Cria a fila*/

    No* novoNo = (No*)malloc(sizeof(No));
    
    if (!novoNo) {
        printf("Falha ao alocar memoria\n");
        exit(1);
    }

    novoNo->data = dado;
    novoNo->proximo = NULL;
    
    if (fila->anterior == NULL) {
        fila->proximo = novoNo;
        fila->anterior = novoNo;
    } else {
        fila->anterior->proximo = novoNo;
        fila->anterior = novoNo;
    }
}

int main (){

    Fila* fila = criaFila();

    populaFila(fila, 10);
    populaFila(fila, 20);
    populaFila(fila, 30);
    populaFila(fila, 40);


    return 0;
}
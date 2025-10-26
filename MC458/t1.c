#include <stdio.h>

int verifica(int set[], int pos[], int valor, int n){
    /*Verifica se o dado esta no vetor*/

    if(pos[valor] != -1 && pos[valor] < n){
        if(set[pos[valor]] == valor){
            return 1;
        }
    }
    return 0;
}

void insere(int set[], int pos[], int valor, int n){    
    /*Insere os dados no vetor*/
    
    pos[valor] = n;
    set[n] = valor;
}

void remover(int set[], int pos[], int valor, int n){    
    /*Remove os elementos do vetor*/

    if(pos[valor] != -1 && pos[valor] < n){
        if(set[pos[valor]] == valor){
            set[pos[valor]] = -1;
        }
    }
}

int main(){

    int n, q, valor;
    char opcao;

    //Entrada inicial
    scanf("%d %d", &n, &q);

    int set[n];
    int pos[n];

    /*Prenche o vetor com posições vazias*/
    for(int i = 0; i<n; i++){
        pos[i] = -1;
        set[i] = -1;
    }

    n = 0;

    //trata as entradas
    for(int i = 0; i<q; i++){
        scanf(" %c", &opcao);

        switch (opcao)
        {
            case 'p':
                scanf("%d", &valor);
                if(verifica(set, pos, valor, n) == 1){
                    printf("1\n");
                }else{
                    printf("0\n");
                }

                break;

            case 'i':
                scanf("%d", &valor);
                insere(set, pos, valor, n);
                n = n + 1;
                break;

            case 'r':
                scanf("%d", &valor);
                remover(set, pos, valor, n);    
                break;

            case 'l':
                n = 0;
                break;
        }
    }
    return 0;
}
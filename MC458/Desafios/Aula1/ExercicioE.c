#include <stdio.h>

void verificaValor(int soma, int d) {
    float media = (float)soma / d;  
    if(media == 1){
        printf("0\n");
    }else if((media) > 1){
        printf("%d\n", (int)(soma - d));  
    }else{
        printf("1\n");
    }
}

int main() {
    int n1 = 0;
    int n2 = 0;
    int aux;
    int soma;

    scanf(" %d", &n1); 

    for (int i = 0; i < n1; i++) {
        scanf(" %d", &n2); 
        soma = 0;
        for(int j = 0; j < n2; j++) {
            scanf(" %d", &aux);
            soma = soma + aux;
        }  
        verificaValor(soma, n2);
    }

    return 0;
}
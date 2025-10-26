#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 10;
    char nome[100];

    printf("Digite seu nome:");
    gets(nome);
    printf("Digite sua idade:");
    scanf("%i", &i);
    
    if(i >= 18){
        printf("\n%s voce e maior de idade!", nome);
    }else{
        printf("\n%s voce e menor de idade!", nome);
    }

    return 0;
}
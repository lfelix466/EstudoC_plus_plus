#include <stdio.h>
#include <stdlib.h>

void retornaElemento(int *p, int indice){

    printf("Valor: %d", *p);

    if(*p == 3){
        printf("Valor encontrado!");
    }else{
        p++;
        retornaElemento(p, indice);
    }

}

int main(){

    int array[] = {1,2,3,4,5}, indice;
    int *p = array;

    printf("Digite o indice que voce acha que esta o valor 3");
    scanf("%d", &indice);

    retornaElemento(p, indice);

    return 0;
}
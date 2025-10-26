#include <stdio.h>
#include <stdlib.h>

int main(){

    int valores[] = {5, 2, 4, 6, 1, 10, 12, 11, 20, 3, 8, 9, 7};
    int menor, j;

    for(int i = 1; i<13; i++){

        menor = valores[i];
        j = i-1;

        while(menor > valores[j] && j > -1){

            valores[j+1] = valores[j];
            valores[j] = menor;
            j = j-1;
            
        }

    }

    for(int i = 0; i<13; i++){

        printf("%d\n", valores[i]);

    }

    return 0;
}
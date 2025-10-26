#include <stdio.h>
#include <stdlib.h>

int main (){

    int cont = 0, matriz1[2][2], matriz2[2][2];

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            matriz1[i][j] = 1;
            matriz2[i][j] = cont;
            cont++;
        }
    }

    printf("Matriz\n");

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            //cont = matriz1[i][j] + matriz2[i][j]; 
            printf("%d ", matriz1[i][j] + matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
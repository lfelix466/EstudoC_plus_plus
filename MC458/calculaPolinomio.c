#include <stdio.h>

int calcula_polinomio(int valores[], int x, int n, int soma){

    if(n == 0){
        return valores[0];
    }else{

        soma = calcula_polinomio(valores, x, n-1, soma);

        if(n > 1){
            x = x*x;
        }

        soma = valores[n]*x + soma;
    }

    return soma;
}



int main(){

    int valores[4], x, n, soma = 0;
    valores[0] = 3;
    valores[1] = 6;
    valores[2] = 3;
    valores[3] = 2;
    n = 4;
    x = 2;

    soma = calcula_polinomio(valores, x, n, soma);

    printf("Soma: %d", soma);

    return 0;    
}
#include <stdio.h>

void menorNumeroCedulas(int valor, int cedulas[], int memoria[], int n){
    /*Calcula o menor numero de celulas para pagar determinado valor*/

        for(int i = 0; i < (valor + cedulas[n-1]); i++){
        for(int j = 0; j<n; j++){

            if(i >= cedulas[j]){
                
                if(i - cedulas[j] == cedulas[j]){
                    memoria[i] = memoria[i - cedulas[j]] + 1;
                }else if(i == cedulas[j]){
                    memoria[i] = 1;
                }else if(memoria[i-cedulas[j] + 1] != -1){
                    if(memoria[i] > memoria[i-cedulas[j]] + 1){
                        memoria[i] = memoria[i - cedulas[j]] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    int valor = 0, n = 0;

    ///Inicia os vetores
    scanf("%d",&valor);
    scanf(" %d",&n);

    int cedulas[n];

    for(int i = 0; i < n; i++){
        scanf(" %d",&cedulas[i]);
    }

    int memoria[(valor + cedulas[n-1])];

    for(int i = 0; i < (valor + cedulas[n-1]); i++){
        memoria[i] = valor + cedulas[n-1];
    }

    menorNumeroCedulas(valor, cedulas, memoria, n);

    //Procura o menor valor suficiente para se pagar com as cedulas
    int cont = valor;
    while(memoria[cont] == valor + cedulas[n-1]){
        cont++;
    }

    printf("%d %d\n", cont, memoria[cont]);

    return 0;
}
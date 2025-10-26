#include <stdio.h>

void printaValores(int valores[], int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("%d ", valores[i]);
    }
    printf("\n");
}

int main()
{

    int dados[2][11];
    int valores[11];

    for (int i = 0; i < 11; i++)
    {
        valores[i] = 0;
        dados[0][i] = i;
    }

    dados[1][0] = 0;
    dados[1][1] = 1;
    dados[1][2] = 5;
    dados[1][3] = 8;
    dados[1][4] = 9;
    dados[1][5] = 10;
    dados[1][6] = 17;
    dados[1][7] = 17;
    dados[1][8] = 20;
    dados[1][9] = 24;
    dados[1][10] = 30;

    for (int i = 1; i < 11; i++){

        for (int j = 1; j < 11; j++){
            
            if (dados[0][j] <= i){

                if (valores[i - dados[0][j]] + dados[1][j] > valores[i]){
                    valores[i] = valores[i - dados[0][j]] + dados[1][j];
                }
            }
        }
        printaValores(valores, 11);
    }
    return 0;
}
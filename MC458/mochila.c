
#include <stdio.h>

void mostraCustos(int custos[][8], int linha, int coluna)
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d", custos[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int itens[5][2];
    // 0 - custo, 1 - peso
    itens[0][0] = 0;
    itens[0][1] = 0;
    itens[1][0] = 10;
    itens[1][1] = 2;
    itens[2][0] = 7;
    itens[2][1] = 1;
    itens[3][0] = 25;
    itens[3][1] = 6;
    itens[4][0] = 24;
    itens[4][1] = 5;

    int custos[5][8];

    int valor1 = 0, valor2 = 0;

    // Inicia a matriz
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            custos[i][j] = 0;
        }
    }

    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            valor1 = 0;
            valor2 = 0;

            // Caso 1
            if (itens[i][1] <= j)
            {
                if (itens[i][0] > custos[i - 1][j])
                {
                    valor1 = itens[i][0];
                }
                else
                {
                    valor1 = custos[i - 1][j];
                }
            }

            // Caso 2
            if (j - itens[i][1] > 0)
            {
                valor2 = custos[i - 1][j - itens[i][1]] + itens[i][0];
            }
            else
            {
                valor2 = custos[i - 1][j];
            }

            if (valor1 > valor2)
            {
                custos[i][j] = valor1;
            }
            else
            {
                custos[i][j] = valor2;
            }
        }
        mostraCustos(custos, 5, 8);
    }
    printf("Maior valor:%d", custos[4][7]);

    return 0;
}
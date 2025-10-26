#include <stdio.h>
#include <stdlib.h>

int maiorValor = 0; // salva o maior valor encontrado dos subconjuntos

void printa(int resultados[][2], int resultado)
{
    /*Funcao que printa os dados*/

    for (int j = 0; j < resultado; j++)
    {
        printf("%i %i\n", resultados[j][0], resultados[j][1]);
    }
}

/*Parte de ordenacao em merge sort*/
void merge(int dados[][2], int esq, int meio, int dir)
{
    int num1 = meio - esq + 1;
    int num2 = dir - meio;

    int(*E)[2] = malloc(num1 * sizeof(int[2]));
    int(*D)[2] = malloc(num2 * sizeof(int[2]));

    for (int i = 0; i < num1; i++)
    {
        E[i][0] = dados[esq + i][0];
        E[i][1] = dados[esq + i][1];
    }
    for (int j = 0; j < num2; j++)
    {
        D[j][0] = dados[meio + 1 + j][0];
        D[j][1] = dados[meio + 1 + j][1];
    }

    int i = 0;
    int j = 0;
    int k = esq;

    while (i < num1 && j < num2)
    {
        if (E[i][0] <= D[j][0])
        {
            dados[k][0] = E[i][0];
            dados[k][1] = E[i][1];
            i++;
        }
        else
        {
            dados[k][0] = D[j][0];
            dados[k][1] = D[j][1];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de E[], se houver
    while (i < num1)
    {
        dados[k][0] = E[i][0];
        dados[k][1] = E[i][1];
        i++;
        k++;
    }

    // Copiar os elementos restantes de D[], se houver
    while (j < num2)
    {
        dados[k][0] = D[j][0];
        dados[k][1] = D[j][1];
        j++;
        k++;
    }

    // Liberar memória alocada
    free(E);
    free(D);
}

void mergeSort(int dados[][2], int esq, int dir)
{
    if (esq < dir)
    {
        int meio = esq + (dir - esq) / 2;

        // Ordenar as duas metades
        mergeSort(dados, esq, meio);
        mergeSort(dados, meio + 1, dir);

        // Mesclar as metades ordenadas
        merge(dados, esq, meio, dir);
    }
}

int calculaMenorSubconjuntos(int dados[][2], int resultados[][2], int n, int valor)
{
    /*Funcao que calcula o menor numero de subconjuntos que cobrem o valor*/

    int resultado = 1;

    resultados[0][0] = dados[0][0];
    resultados[0][1] = dados[0][1];
    maiorValor = dados[0][1];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < resultado; j++)
        {

            if (dados[i][1] > 0)
            {

                if (dados[i][0] <= 0 && dados[i][1] > resultados[j][1])
                {
                    resultado = j;
                    resultados[j][0] = dados[i][0];
                    resultados[j][1] = dados[i][1];
                    maiorValor = dados[i][1];
                    resultado = j + 1;
                    break;
                }
                else if (dados[i][0] <= resultados[j][1])
                {
                    if (dados[i][1] > maiorValor)
                    {
                        resultado = j + 2;
                        resultados[j + 1][0] = dados[i][0];
                        resultados[j + 1][1] = dados[i][1];
                        maiorValor = dados[i][1];
                        break;
                    }
                }
            }
        }

        if (maiorValor >= valor)
        {
            for (int z = i + 1; z < n; z++)
            {
                if (dados[z][0] > resultados[resultado - 2][1])
                {
                    break;
                }
                else
                {

                    if (dados[z][1] > maiorValor)

                    {
                        resultados[resultado - 1][0] = dados[z][0];
                        resultados[resultado - 1][1] = dados[z][1];
                        maiorValor = dados[z][1];
                    }
                }
            }
            break;
        }
    }

    return resultado;
}

int main()
{
    int valor = 0, n = 0, resultado;

    scanf("%i", &valor);
    scanf(" %i", &n);

    // Aloca dinamicamente as matrizes dados e resultados
    int (*dados)[2] = malloc(n * sizeof(int[2]));
    int (*resultados)[2] = malloc(n * sizeof(int[2]));

    if (dados == NULL || resultados == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf(" %i %i", &dados[i][0], &dados[i][1]);
    }

    mergeSort(dados, 0, n - 1); // ordena os dados

    resultado = calculaMenorSubconjuntos(dados, resultados, n, valor);

    /* Printa os dados caso encontrou os subconjuntos ou printa 0 */
    if (maiorValor >= valor)
    {
        printf("%i\n", resultado);
        printa(resultados, resultado);
    }
    else
    {
        printf("0\n");
    }

    // Libera a memória alocada
    free(dados);
    free(resultados);

    return 0;
}
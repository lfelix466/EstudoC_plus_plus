#include <stdio.h>
#include <string.h>

int calculaInversaoString(int n, char vetor[])
{
    /*Calcula a soma de inversao em cada string*/
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (vetor[i] > vetor[j])
            {
                soma = soma + 1;
            }
        }
    }
    return soma;
}

void mostraOrdenado(int n, int inversorVetor[], char vetor[][100])
{
    /*Funcao que mostra os dados em ordem crescente*/
    int indice = 0, valor = inversorVetor[0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (inversorVetor[j] != -1)
            {
                if (valor != -1)
                {
                    if (inversorVetor[j] < valor)
                    {
                        indice = j;
                        valor = inversorVetor[j];
                    }
                }
                else
                {
                    indice = j;
                    valor = inversorVetor[j];
                }
            }
        }
        printf("%s", vetor[indice]);
        printf("\n");
        inversorVetor[indice] = -1;
        valor = -1;
    }
}

void calculaInversao(int n, int m, int inversorVetor[], char vetor[][100])
{
    /*Funcao que calcula o peso de cada String*/
    for (int i = 0; i < n; i++)
    {
        inversorVetor[i] = calculaInversaoString(m, vetor[i]);
    }
}

int main()
{

    int M = 1, n = 0, m = 0;
    char Dados[100][100];
    int somas[100];

    scanf("%i", &M);

    for (int i = 0; i < M; i++)
    {

        scanf("%i ", &m);
        scanf("%i ", &n);

        for (int j = 0; j < n; j++)
        {
            fgets(Dados[j], sizeof(Dados[j]), stdin);
            Dados[j][strcspn(Dados[j], "\n")] = 0;
        }

        calculaInversao(n, m, somas, Dados);
        mostraOrdenado(n, somas, Dados);

        //Pula linha caso tenha mais um conjunto de dados para ser mostrado
        if(i != M-1){
            printf("\n");
        }
    }

    return 0;
}
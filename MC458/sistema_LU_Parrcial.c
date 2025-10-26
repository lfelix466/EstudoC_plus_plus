#include <stdio.h>

void iniciaMatrizes(int n, float P[n][n], float L[n][n], int Ordem[n], float coeficientes[n][n])
{
    /*Inicia as matrizes L,P e coeficientes*/
    int cont = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                P[i][j] = 1.000;
                L[i][j] = 1.000;
            }
            else
            {
                P[i][j] = 0.000;
                L[i][j] = 0.000;
            }
            coeficientes[i][j] = 0;
        }
        Ordem[i] = cont;
        cont++;
    }
}

void exibirMatrix(int n, float m[n][n])
{
    /*Mostrar os dados da matriz passada*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void exibirResultados(int n, float U[n][n], float L[n][n], float P[n][n])
{
    /*Mostra os dados das matrizes*/
    printf("Matriz U:\n");
    exibirMatrix(n, U);

    printf("Matriz P:\n");
    exibirMatrix(n, P);

    printf("Matriz L:\n");
    exibirMatrix(n, L);
}

void trocar_Linha(int n, int linha1, int linha2, float m[n][n])
{
    /*Funcao que troca a linha de uma matriz*/
    float aux = 0.000;

    for (int j = 0; j < n; j++)
    {
        aux = m[linha2][j];
        m[linha2][j] = m[linha1][j];
        m[linha1][j] = aux;
    }
}

void ajustaL(int n, float L[n][n], int Ordem[n], float coeficientes[n][n])
{
    /*Funcao que ajusta L com os coeficientes nas posicoes corretas*/
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                L[i][j] = 1.000;
            }
            else
            {
                L[i][j] = coeficientes[Ordem[i]][j];
            }
        }
    }
}

void multiplicarMatrizes(int n, int coluna, float m1[n][n], float m2[n][n], float m3[n][n])
{
    /*Funcao de multiplicas matrizes*/
    float aux = 0.000;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < coluna; k++)
        {
            for (int j = 0; j < n; j++)
            {
                aux = aux + m1[i][j] * m2[j][k];
            }
            m3[i][k] = aux;
            aux = 0;
        }
    }
}

void removerElementos(int n, int indice, int coluna, float m[n][n], float coeficientes[n][n], int ordem[])
{

    /*Funcao que remove elementos da matriz U
    Alem disso adiciona os coeficientes na matriz de coeficientes*/
    float a1 = 0.000;

    for (int i = indice + 1; i < n; i++)
    {
        a1 = m[i][coluna] / m[indice][coluna];

        for (int j = 0; j < n; j++)
        {
            m[i][j] = m[i][j] - (a1)*m[indice][j];
        }

        // Adiciona os coeficientes na matriz
        coeficientes[ordem[i]][coluna] = a1;
    }
}

void adicionarMatrix(int n, float m1[n][n], float m2[n][n])
{
    /*Funcao que copia os valores de A para U*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m1[i][j] = m2[i][j];
        }
    }
}

void calculaY(int n, float P[n][n], float L[n][n], float B[n][n], float m4[n][n])
{
    /*Funcao que calcula Y*/

    printf("Valores de Y\n");
    float resultado = 0;
    multiplicarMatrizes(n, 1, P, B, m4);

    for (int i = 0; i < n; i++)
    {

        resultado = 0;
        for (int j = 0; j < i + 1; j++)
        {

            if (j == i)
            {
                resultado = resultado + m4[i][0];
            }
            else
            {
                resultado = resultado - L[i][j] * B[j][0];
            }
        }

        B[i][0] = resultado; // adiciona os Ys na matriz B
        printf("Y%d: %.2f\n", i + 1, resultado);
    }
    printf("\n");
}

void calculaX(int n, float U[n][n], float B[n][n], float X[n][n])
{
    /*Funcao que calcula X*/

    printf("Valores de X\n");
    float resultado = 0;

    for (int i = n - 1; i > -1; i--)
    {
        resultado = 0;
        for (int j = n - 1; j > -1; j--)
        {
            if (j == i)
            {
                resultado = (resultado + B[i][0]) / U[i][j];
            }
            else
            {
                resultado = resultado - U[i][j] * X[j][0];
            }
        }
        X[i][0] = resultado;
    }

        
        for(int i = 0; i<n; i++){
            printf("X%d: %.2f\n", i + 1, X[i][0]);
        }
}

int main()
{

    int aux = -1, n;
    int linha1 = -1, linha2 = 0, coluna = 0;
    float maior_valor, entrada;

    printf("Digite o tamamanho do vetor:");
    scanf("%d", &n);

    /// Matrizes
    float A[n][n], B[n][n], U[n][n], P[n][n], L[n][n], coeficientes[n][n];

    // Matriz que guarda a ordem das linhas das matrizes
    int ordem[n];

    /*Pega as entradas*/
    for (int i = 0; i < n; i++)
    {
        printf("Digite os valores das incognitas da linha:%d\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf(" %f", &entrada);
            A[i][j] = entrada;
        }

        printf("Digite o valor da igualdadade:%d", i + 1);
        scanf(" %f", &entrada);
        B[i][0] = entrada;
    }

    adicionarMatrix(n, U, A);
    iniciaMatrizes(n, P, L, ordem, coeficientes);

    int aux2;
    for (int j = 0; j < n - 1; j++)
    {

        linha2 = 0;
        linha1 = linha1 + 1;
        maior_valor = 0;

        for (int i = 0; i < n; i++)
        {
            if ((U[i][j] * U[i][j]) > maior_valor && aux < i)
            {
                maior_valor = U[i][j] * U[i][j];
                linha2 = i;
                coluna = j;
                aux = linha1;
            }
        }

        // ajusta a ordem correta das linhas
        aux2 = ordem[linha1];
        ordem[linha1] = ordem[linha2];
        ordem[linha2] = aux2;

        trocar_Linha(n, linha1, linha2, U);
        trocar_Linha(n, linha1, linha2, P);
        removerElementos(n, linha1, coluna, U, coeficientes, ordem);

        printf("Passo:%d\n\n", j + 1);
        exibirResultados(n, U, L, P);
    }

    printf("//////////////////////////////////////////////\n");
    printf("Resultado final\n");

    ajustaL(n, L, ordem, coeficientes);
    exibirResultados(n, U, L, P);

    calculaY(n, P, L, B, coeficientes);
    calculaX(n, U, B, coeficientes);

    return 0;
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int contString = 0;

typedef struct No
{
    /*Estrutura dos dados*/
    char dado;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char dado)
{
    /*Cria os nos ou as folhas da arvore*/
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->dado = dado;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

void limpaArvore(No *arvore)
{
    /*Limpa os elementos da arvore da memoria*/

    if (arvore->esq != NULL)
    {
        limpaArvore(arvore->esq);
    }

    if (arvore->dir != NULL)
    {
        limpaArvore(arvore->dir);
    }

    free(arvore);
}

void criaArvore(No *arvore)
{
    /*Inicia todos os elementos da arvore*/
    No *aux;

    // Altura 1
    arvore->esq = criarNo('E');
    arvore->dir = criarNo('T');

    // Altura 2
    aux = arvore->esq;
    aux->esq = criarNo('I');
    aux->dir = criarNo('A');
    aux = arvore->dir;
    aux->esq = criarNo('N');
    aux->dir = criarNo('M');

    // Altura 3
    aux = arvore->esq;
    aux = aux->esq;
    aux->esq = criarNo('S');
    aux->dir = criarNo('U');
    aux = arvore->esq;
    aux = aux->dir;
    aux->esq = criarNo('R');
    aux->dir = criarNo('W');

    aux = arvore->dir;
    aux = aux->esq;
    aux->esq = criarNo('D');
    aux->dir = criarNo('K');
    aux = arvore->dir;
    aux = aux->dir;
    aux->esq = criarNo('G');
    aux->dir = criarNo('O');
}

void codigoMorse(No *arvore, const char *signals, int pos, char *valores)
{
    /*Funcao que procura os elementos recursivamente*/
    if (signals[pos] != '\0')
    {
        if (signals[pos] == '?')
        {
            // Verifica ambos os ramos quando o sinal é '?
            if (arvore->esq != NULL)
            {
                codigoMorse(arvore->esq, signals, pos + 1, valores);
            }
            if (arvore->dir != NULL)
            {
                codigoMorse(arvore->dir, signals, pos + 1, valores);
            }
        }
        else if (signals[pos] == '.')
        {
            // Segue para o ramo da esquerda quando for '.'
            if (arvore->esq != NULL)
            {
                codigoMorse(arvore->esq, signals, pos + 1, valores);
            }
        }
        else
        {
            // Segue para o ramo da direita quando for '-'
            if (arvore->dir != NULL)
            {
                codigoMorse(arvore->dir, signals, pos + 1, valores);
            }
        }
    }
    else
    {
        // Quando termina a string Morse, salva o caractere atual
        valores[contString] = arvore->dado;
        contString++;
    }
}

/**
 * @param const char *signals a string de até 3 caracteres Morse
 *     e/ou o curinga '?'.
 * @return char * uma string alocada dinamicamente que representa
 *     todas as combinações possíveis que os sinais podem representar.
 */
char *possibilities(const char *signals)
{
    // Reinicia o contador global
    contString = 0;

    // Criação da árvore de Morse
    No *arvore = criarNo('0');
    criaArvore(arvore);

    // Aloca espaço para armazenar as possibilidades
    char *valores = (char *)calloc(15, sizeof(char));

    // Inicia a recursão para encontrar as combinações
    codigoMorse(arvore, signals, 0, valores);

    // Limpa os elementos da arvore da memeoria
    limpaArvore(arvore);

    return valores;
}

int main()
{

    char *resultado = possibilities("\?.");

    for (int i = 0; i < 3; i++)
    {
        printf("%c", resultado[i]);
    }

    return 0;
}
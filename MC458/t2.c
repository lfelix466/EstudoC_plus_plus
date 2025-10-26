#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int peso;
    struct No *esquerda;
    struct No *direita;
} No;

int cont, maiorCaminho;

No *criaNo()
{
    /*Aloca memoria dos nos*/
    No *novoNo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    novoNo->peso = 0;        // Define os dados
    novoNo->esquerda = NULL; // Inicializa o ponteiro para o filho à esquerda como NULL
    novoNo->direita = NULL;  // Inicializa o ponteiro para o filho à direita como NULL
    return novoNo;
}

No* criaArvore(No *no, char **token) {
    /*Popula itens da arvore*/
    if (*token == NULL) {
        return NULL;
    }

    if ((*token)[0] != 'T' && (*token)[0] != 'F') {
        int numero = atoi(*token);
        no->peso = numero;
        *token = strtok(NULL, " ");
    }

    if (*token != NULL && (*token)[0] == 'T') {
        no->esquerda = criaNo();
        *token = strtok(NULL, " ");
        criaArvore(no->esquerda, token);
    }else{
        *token = strtok(NULL, " ");
    }

    if (*token != NULL && (*token)[0] == 'T') {
        no->direita = criaNo();
        *token = strtok(NULL, " ");
        criaArvore(no->direita, token);
    }else{
        *token = strtok(NULL, " ");
    }

    return no;
}


int maiorValor(No *no)
{
    /*Atualiza a variavel maiorValor*/
    int valor_p_esquerdo = 0, valor_p_direito = 0,
        valorP = 0, valor_somado = 0;

    if (no->esquerda != NULL)
    {
        valor_p_esquerdo = maiorValor(no->esquerda);
    }

    if (no->direita != NULL)
    {
        valor_p_direito = maiorValor(no->direita);
    }

    if (no->peso > valor_somado)
    {
        valor_somado = no->peso;
    }

    if ((valor_p_direito + valor_p_esquerdo + no->peso) > maiorCaminho)
    {
        maiorCaminho = (valor_p_esquerdo + valor_p_direito + no->peso);
    }

    if (valor_p_direito > valor_p_esquerdo)
    {
        valorP = valor_p_direito;
    }
    else
    {
        valorP = valor_p_esquerdo;
    }

    if ((valorP + no->peso) > valor_somado)
    {
        valor_somado = valorP + no->peso;
    }

    if (valor_somado > maiorCaminho)
    {
        maiorCaminho = valor_somado;
    }

    return valor_somado;
}

void liberarNo(No* no) {
    /*Libera os nos da memoria*/
    if (no == NULL) {
        return; 
    }
    
    liberarNo(no->esquerda);
    liberarNo(no->direita);
    
    free(no);
}

int main()
{

    char entrada[1000000]; // Define um buffer com tamanho suficiente
    fgets(entrada, sizeof(entrada), stdin);

    // Remove o caractere de nova linha se estiver presente
    entrada[strcspn(entrada, "\n")] = 0;

    // Usando strtok para dividir a string em tokens
    char *token = strtok(entrada, " ");

    No* arvore = criaNo();
    arvore = criaArvore(arvore, &token);

    maiorValor(arvore);

    /*Saida*/
    if(maiorCaminho <= 0){
        printf("0\n");
    }else{
        printf("%d\n", maiorCaminho);
    }

    liberarNo(arvore);

    return 0;
}
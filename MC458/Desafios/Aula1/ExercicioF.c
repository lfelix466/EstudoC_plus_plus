#include <stdio.h>

int verificaVizinhos(char matriz[][52], int linha, int coluna){

    char valores[4];
    valores[0] = 'f';
    valores[1] = 'a';
    valores[2] = 'c';
    valores[3] = 'e';

    for(int i = 0; i < 4; i++){
        if(matriz[linha][coluna] == valores[i] || matriz[linha+1][coluna] == valores[i] ||
            matriz[linha][coluna+1] == valores[i] || matriz[linha+1][coluna+1] == valores[i]){
            valores[i] = ' ';
        }
    }

    for(int i = 0; i < 4; i++){
        if(valores[i] != ' '){
            return 0;
        }
    }
    return 1;
}

int verificaFace(char matriz[][52], int linha, int coluna) {
    int soma = 0;

    for (int i = 0; i < linha - 1; i++) {
        for (int j = 0; j < coluna - 1; j++) {
                printf("%c", matriz[i][j]);
                if(matriz[i][j] == 'f' || matriz[i][j] == 'a' || matriz[i][j] == 'c' || matriz[i][j] == 'e'){
                    soma = soma + verificaVizinhos(matriz, i, j);
                }   
        }
    }

    return soma;
}

int main() {
    int linhas, colunas;

    scanf("%d %d", &linhas, &colunas);
    char matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf(" %c", &matriz[i][j]); 
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c", matriz[i][j]); 
        }
    }

    printf("%d\n", verificaFace(matriz, linhas, colunas));
    return 0;
}
#include <stdio.h>

void verificaValor(char valor[1000], int n) {
    char nome[5];
    nome[0] = 'T';
    nome[1] = 'i';
    nome[2] = 'm';
    nome[3] = 'u';
    nome[4] = 'r';

    if(n == 5) {
        // Verifica se a string valor contém as letras de "Timur"
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(valor[i] == nome[j]) {
                    nome[j] = '0'; // Marca a letra encontrada como já utilizada
                    valor[i] = ' '; // Substitui a letra encontrada na string
                    break;
                }
            }
        }

        // Verifica se todas as letras foram "usadas" (substituídas por ' ')
        for(int i = 0; i < 5; i++) {
            if(nome[i] != '0') {  // Se alguma letra de "Timur" não foi encontrada, é "NO"
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int n1 = 0;
    int n2 = 0;
    char valor[1000];

    scanf("%d", &n1); 
    getchar();  // Consumir o '\n'

    for (int i = 0; i < n1; i++) {
        scanf("%d", &n2);  
        getchar();  // Consumir o '\n'
        fgets(valor, sizeof(valor), stdin);  
        verificaValor(valor, n2); 
    }

    return 0;
}
#include <stdio.h>

int contaEspacos(char valor[1000], int n) {
    int cont = 0, maiorNum = 0, i = 0, aux = 0;

    // Loop até encontrar o final da string
    while (aux != n) {
        if (valor[i] == '0') {
            cont++;
            aux++;
            if (cont > maiorNum) {
                maiorNum = cont;
            }
        } else if (valor[i] == '1') {
            cont = 0;
            aux++;
        }
        i++;
    }

    return maiorNum;
}

int main() {
    int n1 = 0;
    int n2 = 0;
    char valor[1000];

    scanf("%d", &n1); 
    getchar();  

    for (int i = 0; i < n1; i++) {
        scanf("%d", &n2);  
        getchar();  // Consumir o '\n'
        fgets(valor, sizeof(valor), stdin);  

        printf("%d\n", contaEspacos(valor, n2)); 
    }

    return 0;
}
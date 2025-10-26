#include <stdio.h>

int main() {
    int a = 10;     // Declara uma variável inteira
    int *p = &a;    // Declara um ponteiro para inteiro e inicializa com o endereço de 'a'

    printf("Valor de a: %d\n", a);          // Imprime o valor de 'a'
    printf("Endereço de a: %p\n", (void*)&a); // Imprime o endereço de 'a'
    printf("Valor de p (endereço de a): %p\n", (void*)p); // Imprime o valor de 'p' (endereço de 'a')
    printf("Valor apontado por p: %d\n", *p); // Imprime o valor de 'a' usando o ponteiro

    *p = 20; // Modifica o valor de 'a' através do ponteiro

    printf("Novo valor de a: %d\n", a); // Imprime o novo valor de 'a'

    return 0;
}
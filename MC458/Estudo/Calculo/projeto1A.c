#include <stdio.h>

int main() {
    float A = 1.0f, s = 2.0f;

    while (s > 1.0f) {
        A = A / 2.0f;
        s = 1.0f + A;
    }

    A = 2.0f * A; // Ajuste para encontrar o epsilon correto

    printf("Precisão da maquina para float: %g\n", A);

    return 0;
}

/*Double*/
/*
#include <stdio.h>

int main() {
    double A = 1.0, s = 2.0;

    while (s > 1.0) {
        A = A / 2.0;
        s = 1.0 + A;
    }

    A = 2.0 * A; // Ajuste para encontrar o epsilon correto

    printf("Precisão da máquina para double: %g\n", A);

    return 0;
}
    */
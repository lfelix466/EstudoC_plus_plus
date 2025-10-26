#include <stdio.h>

int main() {
    float A = 1.0f;
    //float Val = 10.0f;
    //float Val = 17.0f;
    //float Val = 100.0f;
    //float Val = 184.0f;
    //float Val = 1000.0f;
    //float Val = 1575.0f;
    //float Val = 10000.0f;
    float Val = 17893.0f;
    float s = Val + A;


    while (s > Val) {
        A = A / 2.0f;
        s = Val + A;
    }

    A = 2.0f * A; // Ajuste para encontrar o epsilon correto

    printf("Precisao da maquina para float: %g\n", A);

    return 0;
}
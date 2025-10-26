#include <stdio.h>
#include <stdlib.h>

int main(){

    double Xo, Yo, h;
    double limite;
    double Xo_aux; 

    printf("Digite o Xo:");
    scanf(" %lf", &Xo);

    printf("\nDigite o Yo:");
    scanf(" %lf", &Yo);

    printf("\nDigite H:");
    scanf(" %lf", &h);

    printf("Digite o limite:");
    scanf(" %lf", &limite);

    int iteracoes = (limite-Xo)/h;
    double k1, k2, k3, k4;

    for(int i = 0; i<iteracoes; i++){

        Xo = Xo + i*h;
        Xo_aux = Xo + h/2;

        k1 = h*(Xo/Yo - Yo/Xo);

        k2 = h*(Xo_aux/(Yo + k1/2) - (Yo + k1/2)/Xo_aux);

        k3 = h*(Xo_aux/(Yo + k2/2) - (Yo + k2/2)/Xo_aux);

        k4 = h*(Xo_aux/(Yo + k3/2) - (Yo + k3/2)/Xo_aux);

        Yo = Yo + (1/6)*(k1 + 2*k2 + 2*k3 + k4);

        printf("\nX:%.2lf", Xo);
        printf("    K1:%.9lf", k1);
        printf("    K2:%.9lf", k2);
        printf("    K3:%.9lf", k3);
        printf("    K4:%.9lf", k4);
        printf("    Y%d:%.9lf",i, Yo);

    }

    return 0;
}
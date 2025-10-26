#include <stdio.h>

int main(){

    float a, b, q, resultado;
    q = 0.0;
    a = 3.0;
    b = 13.0;

    resultado = a-q*b; 

    while((resultado) >= 0.01 || (resultado) <= 0.0){

    if((resultado) >= 0){
        q = q+1;
    }else{
        q = q-0.01;
    }
    resultado = a- q*b;
    }
    printf("%f", q);

    return 0;
}
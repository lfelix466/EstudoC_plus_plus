#include <iostream>

using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int valor = 10;
        int aux = calculaDigitos(num, valor);
        int soma = aux;
        num = (num - aux)/valor;

        if(num != 0){
            
            while(num != 0){
                aux = calculaDigitos(num, valor);
                soma = soma + aux;
                num = (num - aux)/valor;
            }
        
        }else{
            return soma;
        }
        
        return addDigits(soma);
    }

private:
    int calculaDigitos(int num, int valor)
    {
        return num % valor;
    }
};

int main()
{
    Solution sol;

    cout << sol.addDigits(0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

    int numero1;
    int numero2;
    int soma;
    int multiplicacao;
    int divisao;
    int subtracao;

    cout << "OPERACOES MATEMATICAS\n\n";
    cout << "digite o primeiro numero\n";
    cin >> numero1;
    cout << "digite o segundo numero\n";
    cin >> numero2;
    system("cls");
    cout << "Soma: \n";
    soma = numero2 + numero1;
    cout << soma << endl;
    cout << "multiplicacao: \n";
    multiplicacao = numero2 * numero1;
    cout << multiplicacao << endl;
    cout << "divisao: \n";
    divisao = numero2 - numero1;
    cout << divisao << endl;
    cout << "subtracao: \n";
    subtracao = numero2 + numero1;
    cout << subtracao << endl;
    system("pause");
    

    return 0;
}

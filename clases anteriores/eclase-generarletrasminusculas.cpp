/**
 * Crear un programa que permita generar las letras minusculas del alfabeto
*/

#include <iostream>
using namespace std;

void generarMiscululas(char letraInicial = 'a', char letraFinal = 'z') {
    cout << letraInicial << " ";

    if(letraInicial < letraFinal) { // letra < z
        generarMiscululas(letraInicial + 1, letraFinal);
    }
}

int main() {

    generarMiscululas();

    return 0;
}
/**
 * Crear un programa que permita generar las letras minusculas del alfabeto
*/

#include <iostream>
using namespace std;


void generarMayMiscululas(int sumaInicial = 0) {
    char lMinuscula = 'a' + sumaInicial; 
    char lMayuscula = 'A' + sumaInicial;

    cout << lMayuscula << lMinuscula << " ";

    if(sumaInicial < 27) { // letra < z
        sumaInicial++;
        generarMayMiscululas(sumaInicial);
    }
}

int main() {
    generarMayMiscululas();

    cout << "Distancia de las a y A " << 'a' - 'A';

    return 0;
}
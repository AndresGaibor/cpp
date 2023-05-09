/**
* Imprimir solamente el N-ésimo dígito fraccionario de cada numero real 
* (posee parte entera y parte fraccionaria) ingresado.
* Autor: Andres Gaibor
*/

#include <iostream>
#include <cmath>

using namespace std;


float parteDecimal(float numero) {
    return numero - floor(numero);
}

int nesimoRecursivo(float numero, int n) {
    if (n <= 0) {
        return floor(numero);
    }

    numero = parteDecimal(numero) * 10;

    return nesimoRecursivo(numero, n-1);
}

int main() {
    float nDecimal;
    cout << "Ingrese un numero con decimales: ";
    cin >> nDecimal;
    int n;
    cout << "Cual n numero de la parte fraccionaria(decimales) desea obtener: ";
    cin >> n;
    cout << nesimoRecursivo(nDecimal, n);


    return 0;
}
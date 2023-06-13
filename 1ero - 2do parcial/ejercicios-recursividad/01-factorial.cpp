/**
 * Calcular el factorial de cada numero ingresado.
 * Autor: Andres Gaibor
*/

#include <iostream>

using namespace std;

int factorial(int numero) {
    if(numero < 0) {
        cout << "El numero debe ser mayor o igual a 0";
        return 0;
    }

    if(numero == 0) {
        return 1;
    }

    if(numero == 1) {
        return numero;
    }

    return numero * factorial(numero - 1);
}

int main() {
    int numero;

    cout << "Ingrese un numero: ";

    cin >> numero;

    cout << "El factorial de " << numero << " es: " << factorial(numero);

    return 0;
}
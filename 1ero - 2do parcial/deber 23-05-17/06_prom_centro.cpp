/**
* Calcular el promedio de los elementos que ocupan las posiciones centrales de una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

bool esPosicionCentral(int contador, int longitudPila) {
    int posicionCentral = longitudPila / 2;
    return (contador == posicionCentral || contador == posicionCentral + 1);
}

float calcularPromedio(int suma, int contador) {
    if (contador == 0) {
        return 0;
    }

    float promedio = suma / contador;
    return promedio;
}

float calcularPromedioPosicionesCentrales(Pila p) {
    int suma = 0;
    int contador = 0;
    int i = 0;
    int longitudPila = p.longitudPila();

    while (!p.isEmpty()) {
        int elemento = p.pop();

        if (esPosicionCentral(i, longitudPila)) {
            suma += elemento;
            contador++;
        }
        i++;
    }

    float promedio = calcularPromedio(suma, contador);
    return promedio;
}



int main() {
    Pila p;

    p.leer();

    cout << endl << "El promedio de los elementos que ocupan las posiciones centrales de la pila es: " << calcularPromedioPosicionesCentrales(p);

    return 0;
}
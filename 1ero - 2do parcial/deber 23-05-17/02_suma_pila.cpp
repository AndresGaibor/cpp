/**
* Calcular la suma de los elementos de una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

int sumaPila(Pila p, int suma = 0) {
    if(p.isEmpty()) {
        return suma;
    }

    suma += p.pop();

    return suma + sumaPila(p);
}

int main() {
    Pila p;

    p.leer();

    cout << endl << "el valor maximo es" << sumaPila(p);

    return 0;
}
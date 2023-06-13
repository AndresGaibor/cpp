/**
* Implementar el ordenamiento por inserción en una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

void ordenarPorInsercion(Pila& p) {
    if (p.isEmpty()) {
        return;
    }

    Pila pilaOrdenada;
    pilaOrdenada.push(p.pop());

    while (!p.isEmpty()) {
        int elemento = p.pop();

        // Mover los elementos mayores al tope de la pila ordenada
        while (!pilaOrdenada.isEmpty() && pilaOrdenada.getTope() > elemento) {
            p.push(pilaOrdenada.pop());
        }

        pilaOrdenada.push(elemento);
    }

    // Revertir la pila ordenada para obtener el orden ascendente
    Pila pilaFinal;
    while (!pilaOrdenada.isEmpty()) {
        pilaFinal.push(pilaOrdenada.pop());
    }

    p = pilaFinal;
}

int main() {
    Pila p;

    p.leer();

    ordenarPorInsercion(p);

    p.mostrar();

    return 0;
}
/**
* Insertar N elementos en las posiciones centrales de una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../../utilidades/pila.h"

using namespace std;

bool esPosicionCentral(int contador, int longitudPila) {
    int posicionCentral = longitudPila / 2;
    return (contador == posicionCentral || contador == posicionCentral + 1);
}

void leerElemento(Pila *p) {
    int elemento;
    cout << "Ingrese un elemento: ";
    cin >> elemento;
    p->push(elemento);
}

void insertNValoresEnPosicionesCentral(Pila *p, int n) {
    int longitudPila = p->longitudPila();

    Pila p2;

    for(int i = 0; i < longitudPila / 2; i++) {
        if(esPosicionCentral(i, longitudPila)) {
            for(int j = 0; j < n; j++) {
                leerElemento(&p2);
            }
        }

        p2.push(p->pop());
    }

    while(!p2.isEmpty()) {
        p->push(p2.pop());
    }
}


int main() {
    Pila p;

    p.leer();

    int n = 1;

    cout << endl << "Ingrese el numero de elementos a insertar: ";
    cin >> n;

    insertNValoresEnPosicionesCentral(&p, n);

    p.mostrar();

    return 0;
}
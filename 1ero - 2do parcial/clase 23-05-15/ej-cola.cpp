#include <iostream>
#include "../utilidades/cola.h"

using namespace std;

bool continuar() {
    int opt;

    cout << endl << "Desea continuar? (1 = si, otro numero = no): ";
    cin >> opt;

    return opt == 1;
}

void leerCola(Cola *c) {
    if (c->isFull()) {
        cout << endl << "La cola esta llena";
        return;
    }

    int dato;

    cout << endl << "Ingrese un dato: ";
    cin >> dato;
    c->enqueue(dato);

    if(!continuar()) {
        return;
    }

    leerCola(c);
}

void mostrarCola(Cola c) {
    if (c.isEmpty()) {
        return;
    }     

    if(c.CanDequeue()) {
        cout << endl << "Elemento [" << c.getFrente() << "]: " << c.dequeue();
    } else {
        cout << endl << "No se puede desencolar (cola vacia)";
    }

    mostrarCola(c);
}

int main() {
    Cola c;

    leerCola(&c);
    
    mostrarCola(c);

    return 0;
}
/**
* Ingresar una pila de elementos entre los cuales se admite 
* únicamente hasta N valores repetidos 
* (Si se alcanza dicho valor, se aceptarán solamente valores únicos.
* Autor: Andres Gaibor
*/

#include <iostream>
// #include <string>
#include "../../utilidades/pila.h"

using namespace std;

int veces(Pila p, int dato, int v = 1) {
    if(p.isEmpty()) {
        return v;
    }

    int a = p.pop();

    if(a == dato) {
        v++;
    }

    return veces(p, dato, v);
}

void leerPila(Pila *p,int n) {
   if (p->isFull()) {
        cout << endl << "La pila esta llena";
        return;
    }

    string linea;
    cout << endl << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty()) {
        return;
    }

    int dato = stoi(linea);
    
    if(veces(*p, dato) == n) {
        cout << endl << "No se puede ingresar mas veces el valor " << dato;
    } else {
        p->push(dato);
    }

    leerPila(p, n);
}

int main() {
    Pila p;

    int n = 0;

    cout << endl << "Ingrese el numero de veces que se puede repetir un valor: ";
    cin >> n;

    cin.ignore();

    leerPila(&p, n);

    p.mostrar();

    return 0;
}
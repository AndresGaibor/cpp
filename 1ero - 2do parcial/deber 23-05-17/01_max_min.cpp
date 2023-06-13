/**
* Encontrar el máximo y mínimo elemento de una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

// - p2 es la pila auxiliar que recibe la misma pila que p como parametro
// - max por defecto es 1, la funcion devuelve el valor maximo, max = -1 devuelve el valor minimo
int valorMax(Pila p, Pila p2, int max = 1) {
    if(p.isEmpty()) {
    return p2.pop();
    }
    
    if (p2.isEmpty()) {
        return p.pop();
    }

    int a = p.pop(), 
        b = p2.pop(); 

    if(a * max > b * max) {
    
        p.push(a);
    } else {
        p2.push(b);
    }

    return valorMax(p, p2, max);
}

// - p2 es la pila auxiliar que recibe la misma pila que p como parametro
int valorMin(Pila p, Pila p2) {
    return valorMax(p, p2, -1);
}

int main() {
    Pila p;

    p.leer();

    cout << endl << "el valor maximo es" << valorMax(p, p);

    cout << endl << "el valor minimo es" << valorMin(p, p);

    return 0;
}
/**
* Intercambiar, por parejas, los elementos de una pila previamente ingresada
*  (primero con segundo, tercero con cuarto, etc.).
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../../utilidades/pila.h"

using namespace std;


void invertirPila(Pila *p, Pila p2, int i = 0) {
    if(p2.isEmpty()) {
        return;
    }

    if(i == 0) {
        p->vaciarPila();
        i = 1;
    }

    p->push(p2.pop());

    invertirPila(p, p2, i);
}

void intercambiar(Pila *p, Pila p2, int i = 0) {
    if(p2.isEmpty()) {
        invertirPila(p, *p);
        return;
    }

    if(i == 0) {
        i = 1;
        p->vaciarPila();
    }
    
    int a = p2.pop();

    if(p2.CanPop()) {
        int b = p2.pop();
        p->push(b);
    }
    
    p->push(a);

    intercambiar(p, p2, i);
}

int main() {
    Pila p;

    p.leer();

    intercambiar(&p, p);
    
    p.mostrar();

    return 0;
}
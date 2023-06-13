#include <iostream>
#include "../../utilidades/pila.h"

using namespace std;


int main() {
    Pila p;

    p.push(1);
    p.push(2);

    cout << p.pop() << endl;

    cout << "pila llena: " << p.estaLlena() << endl;
    cout << "pila vacia: " << p.estaVacia() << endl;

    return 0;
}
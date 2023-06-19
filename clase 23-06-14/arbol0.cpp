/**
 * 
 * Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/nodoArbol.h"

using namespace std;

int main() {
    NodoBinario n1, n2, n3, n4, n5;

    n1 = NodoBinario(100, &n2, &n3); // Padre

    n2 = NodoBinario(25, &n4, &n5);
    n3.setDato(38);

    n4.setDato(45); // hojas
    n5.setDato(50);
    
    cout << endl << "valor almacenado en el nodo n4 (hijo izq) " << n4.getDato();
    cout << endl << "valor almacenado en el nodo 2 (padre n4) " << n4.getPadre()->getDato();
    cout << endl << "valor almacenado en el nodo 1 (padre n2) " << n4.getPadre()->getPadre()->getDato();

    cout << endl;
    
    return 0;
}
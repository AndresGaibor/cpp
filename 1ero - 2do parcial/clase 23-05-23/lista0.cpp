/**
 * Usando lista con nodos
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/nodo.h"

using namespace std;


int main()
{
    Nodo n, 
        n2(105), 
        n3(&n2), 
        n4(104, &n3);

    n3.setDato(106);


    cout << endl << "valor almacenado en el nodo " << n4.getDato();
    cout << endl << "valor almacenado en el nodo " << n4.getSiguiente()->getDato();
    cout << endl << "valor almacenado en el nodo " << n4.getSiguiente()->getSiguiente()->getDato();
    cout << endl << "valor almacenado en el nodo " << n4.getSiguiente()->getSiguiente()->getSiguiente();


    return 0;
}
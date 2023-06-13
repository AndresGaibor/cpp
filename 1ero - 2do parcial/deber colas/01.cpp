/**
 * Eliminar los valores repetidos en una cola previamente ingresada
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>

#include "../utilidades/colaCircular.h"

using namespace std;

void eliminarRepetidos(ColaCircular &cola) // con ciclos
{
    ColaCircular aux;
    Tipo valor;

    while (!cola.isEmpty())
    {
        valor = cola.dequeue();

        if (!aux.buscar(aux, valor))
        {
            aux.enqueue(valor);
        }
    }

    cola = aux;
}

int main()
{
    ColaCircular c;

    c.leer();

    cout << "Cola original: " << endl;
    c.mostrar(c);

    eliminarRepetidos(c);

    cout << "Cola sin repetidos: " << endl;
    c.mostrar(c);

    return 0;
}
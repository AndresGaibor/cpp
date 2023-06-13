/**
 * Intercambiar las posiciones pares con las impares dentro de un TDA Cola ingresado previamente
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>
#include "../utilidades/colaCircular.h"

using namespace std;

void intercambiar(ColaCircular *cola)
{
    ColaCircular aux;
    Tipo valor;

    while (!cola->isEmpty())
    {
        valor = cola->dequeue();
        aux.enqueue(valor);
    }

    while (!aux.isEmpty())
    {
        valor = aux.dequeue();
        if (!aux.isEmpty())
        {
            cola->enqueue(aux.dequeue());
        }
        cola->enqueue(valor);
    }
}

int main()
{

    ColaCircular c;

    c.leer();

    cout << "Cola original: " << endl;
    c.mostrar(c);
    cout << endl;

    intercambiar(&c);

    cout << "Cola intercambiada: " << endl;
    c.mostrar(c);

    return 0;
}
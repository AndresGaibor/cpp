/**
 * Permitir el ingreso de una cadena de caracteres y ordenar los caracteres de cada palabra encontrada
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef char Tipo;

#include <iostream>
#include "../utilidades/colaCircular.h"

using namespace std;

void ordenarPalabras(ColaCircular *cola)
{
    ColaCircular aux;
    Tipo a, b;

    while (!cola->isEmpty())
    {
        a = cola->dequeue();

        if (a == ' ')
        {
            aux.enqueue(a);
        }
        else
        {
            if (!cola->isEmpty())
            {
                b = cola->dequeue();
                if (a > b)
                {
                    aux.enqueue(a);
                    aux.enqueue(b);
                }
                else
                {
                    aux.enqueue(b);
                    aux.enqueue(a);
                }
            }
        }
    }

    *cola = aux;
}

int main()
{
    cout << "Ingrese una cadena de caracteres: ";
    ColaCircular c;
    c.leerChar();

    return 0;
}
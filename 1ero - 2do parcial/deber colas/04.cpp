/**
 * Ingresar ordenadamente los valores en una cola
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>
#include "../utilidades/colaCircular.h"

using namespace std;

void leerCola(ColaCircular *cola)
{
    if (cola->isFull())
    {
        cout << endl
             << "La cola esta llena";
        return;
    }

    string linea;
    cout << endl
         << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return;
    }

    int dato = stoi(linea);
    cola->enqueueOrdered(dato);

    leerCola(cola);
}

int main()
{
    ColaCircular c;

    leerCola(&c);

    cout << "Cola: " << endl;
    c.mostrar(c);

    return 0;
}
/**
 * Generar una pila ordenada descendentemente con los valores
 * comunes a varias colas ingresadas
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>
#include "../../utilidades/colaCircular.h"
#include "../../utilidades/pila.h"

using namespace std;

void generarPila(ColaCircular *c1, ColaCircular *c2, ColaCircular *c3, Pila *pila)
{
    Tipo valor;

    while (!c1->isEmpty())
    {
        valor = c1->dequeue();
        if (c2->buscar(*c2, valor) && c3->buscar(*c3, valor))
        {
            pila->push(valor);
        }
    }

    while (!c2->isEmpty())
    {
        valor = c2->dequeue();
        if (c1->buscar(*c1, valor) && c3->buscar(*c3, valor))
        {
            pila->push(valor);
        }
    }

    while (!c3->isEmpty())
    {
        valor = c3->dequeue();
        if (c1->buscar(*c1, valor) && c2->buscar(*c2, valor))
        {
            pila->push(valor);
        }
    }
}

int main()
{
    ColaCircular c1, c2, c3;
    Pila pila;

    cout << "Ingrese los valores de la primera cola: " << endl;
    c1.leer();

    cout << "Ingrese los valores de la segunda cola: " << endl;
    c2.leer();

    cout << "Ingrese los valores de la tercera cola: " << endl;
    c3.leer();

    cout << "Pila con los valores comunes: " << endl;
    generarPila(&c1, &c2, &c3, &pila);

    pila.mostrar();

    return 0;
}
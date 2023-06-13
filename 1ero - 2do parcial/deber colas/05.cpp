/**
 * Encontrar la unión entre varias TDA colas ingresadas
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>

#include "../utilidades/colaCircular.h"

using namespace std;

void eliminarValoresDuplicados(ColaCircular *c)
{
    ColaCircular aux;
    Tipo a = -10000, b;

    while (!c->isEmpty())
    {
        b = c->dequeue();

        if (b != a)
        {
            aux.enqueue(b);
        }

        a = b;
    }

    *c = aux;
}

void unirColas(ColaCircular *c1, ColaCircular *c2, ColaCircular *c3)
{
    ColaCircular aux;
    Tipo valor;

    while (!c1->isEmpty())
    {
        valor = c1->dequeue();
        aux.enqueue(valor);
    }

    while (!c2->isEmpty())
    {
        valor = c2->dequeue();
        aux.enqueue(valor);
    }

    while (!c3->isEmpty())
    {
        valor = c3->dequeue();
        aux.enqueue(valor);
    }

    eliminarValoresDuplicados(&aux);

    *c1 = aux;
}

int main()
{
    ColaCircular c1, c2, c3;

    cout << "Ingrese los valores de la primera cola: " << endl;
    c1.leer();

    cout << "Ingrese los valores de la segunda cola: " << endl;
    c2.leer();

    cout << "Ingrese los valores de la tercera cola: " << endl;
    c3.leer();

    cout << "Union de las colas: " << endl;
    unirColas(&c1, &c2, &c3);

    c1.mostrar(c1);

    return 0;
}
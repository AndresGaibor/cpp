/**
 *  Intercambiar los elementos de posiciones pares con los de las impares de una lista ingresada
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "lista.h"

#define EXT 99
#define FIN 99999

using namespace std;

void ingresarNumeros(Lista *lista)
{
    int valor;

    cout << "Ingrese un numero (SALGA CON " << FIN << " )" << endl;
    cin >> valor;

    if (valor != FIN)
    {
        lista->insertarFinal(valor);

        ingresarNumeros(lista);
    }
}

void imprimirNumeros(Nodo *p)
{
    if (p == NULL)
    {
        return;
    }

    cout << "> " << p->getDato() << endl;

    imprimirNumeros(p->getSiguiente());
}

void intercambiarParesImparesRecursivo(Nodo *p, bool esPar = true)
{
    if (p == NULL || p->getSiguiente() == NULL)
    {
        return;
    }

    if (esPar)
    {
        // Intercambiar el dato del nodo actual con el siguiente
        int temp = p->getDato();
        p->setDato(p->getSiguiente()->getDato());
        p->getSiguiente()->setDato(temp);
    }

    intercambiarParesImparesRecursivo(p->getSiguiente(), !esPar);
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    intercambiarParesImparesRecursivo(lista.getPrimero());

    cout << "Impresion de lista intercambiada pares con impares" << endl;
    imprimirNumeros(lista.getPrimero());

    return 0;
}
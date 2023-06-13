/**
 *
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

bool estaOrdenadaRecursivo(Nodo *p)
{
    if (p == nullptr || p->getSiguiente() == nullptr)
    {
        return true;
    }

    if (p->getDato() > p->getSiguiente()->getDato())
    {
        return false;
    }

    return estaOrdenadaRecursivo(p->getSiguiente());
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    cout << "La lista esta " << (estaOrdenadaRecursivo(lista.getPrimero()) ? "ordenada" : "desordenada") << endl;

    return 0;
}
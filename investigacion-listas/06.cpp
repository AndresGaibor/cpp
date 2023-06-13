/**
 *  Eliminar el penúltimo nodo de una lista ingresada
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

void eliminarPenultimoRecursivo(Nodo *p)
{
    if (p == NULL || p->getSiguiente() == NULL || p->getSiguiente()->getSiguiente() == NULL)
    {
        return;
    }

    if (p->getSiguiente()->getSiguiente()->getSiguiente() == NULL)
    {
        Nodo *penultimo = p->getSiguiente();
        p->setSiguiente(penultimo->getSiguiente());
        delete penultimo;
        return;
    }

    eliminarPenultimoRecursivo(p->getSiguiente());
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    cout << "Eliminando penultimo nodo" << endl;
    eliminarPenultimoRecursivo(lista.getPrimero());

    cout << "Impresion de lista sin el penultimo nodo" << endl;
    imprimirNumeros(lista.getPrimero());

    return 0;
}
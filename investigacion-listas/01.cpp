/**
 * Encontrar el rango de una lista de valores ingresados
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

int encontrarRango(Lista *lista)
{
    if (lista->esVacia())
    {
        return 0;
    }

    Nodo *p = lista->getPrimero();
    int minValor = p->getDato();
    int maxValor = p->getDato();

    while (p != NULL)
    {
        int dato = p->getDato();
        if (dato < minValor)
        {
            minValor = dato;
        }
        if (dato > maxValor)
        {
            maxValor = dato;
        }
        p = p->getSiguiente();
    }

    return maxValor - minValor;
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    cout << "Rango: " << encontrarRango(&lista) << endl;

    return 0;
}
/**
 * Generar una lista con los nodos externos de un árbol previamente ingresado
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/lista.h"
#include "../utilidades/arbolBinario.h"

using namespace std;

void generarListaHojas(NodoBinario *nodo, Lista *hojas)
{
    if (nodo == nullptr)
    {
        return;
    }

    if (nodo->getHijoIzquierdo() == nullptr && nodo->getHijoDerecho() == nullptr)
    {
        hojas->insertarFinal(nodo->getDato());
    }

    generarListaHojas(nodo->getHijoIzquierdo(), hojas);
    generarListaHojas(nodo->getHijoDerecho(), hojas);
}

void imprimirLista(Nodo *nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    cout << nodo->getDato() << " ";

    imprimirLista(nodo->getSiguiente());
}

int main()
{
    ArbolBinario arbol;
    arbol.leer();

    Lista hojas;

    generarListaHojas(arbol.getRaiz(), &hojas);

    cout << endl
         << "Lista de hojas: " << endl;
    imprimirLista(hojas.getPrimero());

    return 0;
}
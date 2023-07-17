/**
 * Imprimir el subárbol que tiene como nodo raíz el valor menor de un AB ingresado
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"

using namespace std;

NodoBinario *encontrarMenorNodo(NodoBinario *nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    NodoBinario *minNodo = nodo;

    NodoBinario *minIzq = encontrarMenorNodo(nodo->getHijoIzquierdo());
    NodoBinario *minDer = encontrarMenorNodo(nodo->getHijoDerecho());

    if (minIzq != nullptr && minIzq->getDato() < minNodo->getDato())
    {
        minNodo = minIzq;
    }
    if (minDer != nullptr && minDer->getDato() < minNodo->getDato())
    {
        minNodo = minDer;
    }

    return minNodo;
}

void imprimirSubarbol(NodoBinario *raiz, ArbolBinario *arbol)
{
    NodoBinario *minNodo = encontrarMenorNodo(raiz);

    cout << "Subárbol con nodo raíz de valor mínimo (" << minNodo->getDato() << "):" << endl;
    arbol->imprimirABJerarquia(minNodo, 0);
}

int main()
{
    ArbolBinario arbol;
    arbol.leer();

    imprimirSubarbol(arbol.getRaiz(), &arbol);

    return 0;
}
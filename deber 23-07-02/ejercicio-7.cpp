/**
 * Calcular el ABB resultante de la unión de 2 ABB originales, previamente ingresados
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"

NodoBinario *unirABB(NodoBinario *raiz1, NodoBinario *raiz2)
{
    if (raiz1 == nullptr)
        return raiz2;
    if (raiz2 == nullptr)
        return raiz1;

    NodoBinario *nuevaRaiz = nullptr;

    if (raiz1->getDato() < raiz2->getDato())
    {
        nuevaRaiz = new NodoBinario(raiz1->getDato());
        nuevaRaiz->setHijoIzquierdo(unirABB(raiz1->getHijoIzquierdo(), raiz2));
        nuevaRaiz->setHijoDerecho(raiz1->getHijoDerecho());
    }
    else if (raiz1->getDato() > raiz2->getDato())
    {
        nuevaRaiz = new NodoBinario(raiz2->getDato());
        nuevaRaiz->setHijoIzquierdo(raiz2->getHijoIzquierdo());
        nuevaRaiz->setHijoDerecho(unirABB(raiz1, raiz2->getHijoDerecho()));
    }
    else
    {
        nuevaRaiz = new NodoBinario(raiz1->getDato());
        nuevaRaiz->setHijoIzquierdo(unirABB(raiz1->getHijoIzquierdo(), raiz2->getHijoIzquierdo()));
        nuevaRaiz->setHijoDerecho(unirABB(raiz1->getHijoDerecho(), raiz2->getHijoDerecho()));
    }

    return nuevaRaiz;
}

int main()
{
    ArbolBinario abb1;
    ArbolBinario abb2;

    cout << "Ingrese los valores del primer ABB separados por espacios: ";
    abb1.leer();

    cout << "Ingrese los valores del segundo ABB separados por espacios: ";
    abb2.leer();

    NodoBinario *unionABB = unirABB(abb1.getRaiz(), abb2.getRaiz());

    ArbolBinario abbUnion;
    abbUnion.setRaiz(unionABB);

    cout << "El ABB resultante de la unión de los dos ABB originales es:" << endl;
    abbUnion.recorrerEnInorden();

    return 0;
}
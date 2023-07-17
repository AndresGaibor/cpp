/**
 * Calcular el rango (diferencia entre el valor mayor y el menor) de un ABB ingresado
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"

#define MAX 9999;

using namespace std;

void encontrarValorMinimo(NodoBinario *raiz, int &minValor)
{
    if (raiz == nullptr)
    {
        return;
    }

    if (raiz->getDato() < minValor)
    {
        minValor = raiz->getDato();
    }

    encontrarValorMinimo(raiz->getHijoIzquierdo(), minValor);
    encontrarValorMinimo(raiz->getHijoDerecho(), minValor);
}

void encontrarValorMaximo(NodoBinario *raiz, int &maxValor)
{
    if (raiz == nullptr)
    {
        return;
    }

    if (raiz->getDato() > maxValor)
    {
        maxValor = raiz->getDato();
    }

    encontrarValorMaximo(raiz->getHijoIzquierdo(), maxValor);
    encontrarValorMaximo(raiz->getHijoDerecho(), maxValor);
}

int calcularRango(NodoBinario *raiz)
{
    int minValor = raiz->getDato();
    int maxValor = raiz->getDato();

    encontrarValorMinimo(raiz, minValor);
    encontrarValorMaximo(raiz, maxValor);

    return maxValor - minValor;
}

int main()
{
    ArbolBinario arbol;

    arbol.leer();

    cout << "El rango del arbol es: " << calcularRango(arbol.getRaiz()) << endl;

    return 0;
}
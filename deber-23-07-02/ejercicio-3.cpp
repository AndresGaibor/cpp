/**
 * Determinar el valor numéricamente menor más cercano a
 * la hoja más alejada de la raíz de un AB ingresado
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"
#define MAX 20
#define FIN 9999

using namespace std;

void recorrerNiveles(NodoBinario *nodo, int *altura, int *min, int nivel = 0)
{
    if (nodo == nullptr)
    {
        return;
    }

    if (nivel > *altura && nodo->getHijoIzquierdo() == nullptr && nodo->getHijoDerecho() == nullptr)
    {
        if (nodo->getDato() < *min)
        {
            *min = nodo->getDato();
            *altura = nivel;
        }
    }

    recorrerNiveles(nodo->getHijoIzquierdo(), altura, min, nivel + 1);
    recorrerNiveles(nodo->getHijoDerecho(), altura, min, nivel + 1);
}

void mayorValorPorNivel(NodoBinario *raiz)
{
    int altura = 0, min = FIN;
    recorrerNiveles(raiz, &altura, &min);

    cout << endl
         << "El valor menor mas cercano a la hoja mas alejada de la raiz es: " << min << endl;
}

int main()
{
    ArbolBinario arbol;
    arbol.leer();

    mayorValorPorNivel(arbol.getRaiz());

    return 0;
}
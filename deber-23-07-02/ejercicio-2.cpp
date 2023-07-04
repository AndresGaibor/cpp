/**
 * Determinar el valor mayor de cada nivel de un AB
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"

#define MAX 20

using namespace std;

void recorrerNiveles(NodoBinario *nodo, Tipo niveles[MAX], int *i, int nivel = 0)
{
    if (nodo == nullptr)
    {
        if (nivel > *i)
        {
            *i = nivel;
        }

        return;
    }

    if (niveles[nivel] == -1 || nodo->getDato() > niveles[nivel])
    {
        niveles[nivel] = nodo->getDato();
    }

    recorrerNiveles(nodo->getHijoIzquierdo(), niveles, i, nivel + 1);
    recorrerNiveles(nodo->getHijoDerecho(), niveles, i, nivel + 1);
}

void nivelesPorDefecto(Tipo niveles[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        niveles[i] = -1;
    }
}

void mayorValorPorNivel(NodoBinario *raiz)
{
    Tipo valoresMayores[MAX];
    nivelesPorDefecto(valoresMayores); // hay inicializar los valores del vector porque al recorrer el arbol
                                       // se comparan con el vector, y por defecto tiene un valor de 32767

    int niveles = 0;

    recorrerNiveles(raiz, valoresMayores, &niveles);

    cout << endl
         << "Los valores mayores de cada nivel son: " << endl;

    for (int i = 0; i < niveles; i++)
    {
        cout << "Nivel " << i << " : " << valoresMayores[i] << endl;
    }
}

int main()
{
    ArbolBinario arbol;

    arbol.leer();

    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    mayorValorPorNivel(arbol.getRaiz());

    return 0;
}
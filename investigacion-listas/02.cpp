/**
 * Formar una lista con los valores pares y otra con valores impares de una lista ingresada
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

void separarParesImparesRecursivo(Nodo *p, Lista *pares, Lista *impares)
{
    if (p == NULL)
    {
        return;
    }

    int dato = p->getDato();
    if (dato % 2 == 0)
    {
        pares->insertarFinal(dato);
    }
    else
    {
        impares->insertarFinal(dato);
    }

    separarParesImparesRecursivo(p->getSiguiente(), pares, impares);
}

int main()
{
    Lista lista, pares, impares;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    separarParesImparesRecursivo(lista.getPrimero(), &pares, &impares);

    cout << "Impresion de pares" << endl;
    imprimirNumeros(pares.getPrimero());

    cout << "Impresion de impares" << endl;
    imprimirNumeros(impares.getPrimero());

    return 0;
}
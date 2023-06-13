/**
 * Listas Circulares
 * Autor: Andres Gaibor
 */

#define FIN 99999

#include <iostream>
#include "listaDoble.h"

using namespace std;

void ingresarNumeros(ListaDoble *lista)
{
    int valor;

    cout << "Ingrese el codigo de estudiante (SALGA CON " << FIN << " )" << endl;
    cin >> valor;

    if (valor != FIN)
    {
        cout << "lista " << (lista->esVacia() ? "vacia" : "no vacia") << endl;
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

int main()
{
    ListaDoble doble;

    ingresarNumeros(&doble);

    imprimirNumeros(doble.getPrimero());

    return 0;
}
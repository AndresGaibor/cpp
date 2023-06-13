/**
 * Listas Circulares
 * Autor: Andres Gaibor
 */

#define FIN 99999

#include <iostream>
#include "listaCircular.h"

using namespace std;

void ingresarNumeros(ListaCircular *lista)
{
    int valor;

    cout << "Ingrese el codigo de estudiante (SALGA CON " << FIN << " )" << endl;
    cin >> valor;

    if (valor != FIN)
    {
        lista->insertarFinal(valor);

        ingresarNumeros(lista);
    }
}

void imprimirNumeros(Nodo *p, Nodo *primer, int rot)
{
    if (rot == 0)
    {
        return;
    }

    cout << "Estudiante #" << p->getDato() << endl;

    if (p->getSiguiente() == primer)
    {
        rot--;
    }

    imprimirNumeros(p->getSiguiente(), primer, rot);
}

int main()
{
    ListaCircular circular;

    ingresarNumeros(&circular);

    int rotaciones;
    cout << "Cuantas veces desea rotar la lista: " << endl;
    cin >> rotaciones;

    imprimirNumeros(circular.getPrimero(), circular.getPrimero(), rotaciones);

    return 0;
}
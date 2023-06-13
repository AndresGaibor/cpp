/**
 * Ingreso de codigo de estudiantes en una lista
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

    cout << "Ingrese el codigo de estudiante (SALGA CON " << FIN << " )" << endl;
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

    cout << "Estudiante #" << p->getDato() << endl;

    imprimirNumeros(p->getSiguiente());
}
// ingresasar el dato, puede estar en la mitad, al final o al inicio
void ingresarEstudiante(Lista *lista)
{
    int valor;

    cout << "Ingrese el codigo de estudiante: " << endl;
    cin >> valor;

    Nodo *p = lista->getPrimero();

    if (p == NULL || p->getDato() > valor)
    {
        lista->insertarInicio(valor);
        return;
    }

    p = p->getSiguiente();
    Nodo *ant = NULL;

    while (p != NULL)
    {
        int dato = p->getDato();

        if (dato > valor)
        {
            Nodo *nuevo = new Nodo(valor);

            nuevo->setSiguiente(p);

            if (ant != NULL)
                ant->setSiguiente(nuevo);
            else
                lista->setPrimero(nuevo); // Actualizar el primer nodo de la lista

            return;
        }

        ant = p;
        p = p->getSiguiente();
    }
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Codigos de estudiantes" << endl;
    imprimirNumeros(lista.getPrimero());

    ingresarEstudiante(&lista);

    cout << "Codigos de estudiantes" << endl;
    imprimirNumeros(lista.getPrimero());

    return 0;
}
/**
 * Ordenar los valores de una lista de números en base a la cantidad de dígitos que posee
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
int contarDigitosRecursivo(int numero)
{
    if (numero < 10)
    {
        return 1;
    }

    return 1 + contarDigitosRecursivo(numero / 10);
}

void ordenarPorDigitosRecursivo(Nodo *p)
{
    if (p == NULL || p->getSiguiente() == NULL)
    {
        return;
    }

    Nodo *actual = p;
    Nodo *siguiente = p->getSiguiente();

    while (siguiente != NULL)
    {
        int digitosActual = contarDigitosRecursivo(actual->getDato());
        int digitosSiguiente = contarDigitosRecursivo(siguiente->getDato());

        if (digitosActual > digitosSiguiente)
        {
            // Intercambiar los datos de los nodos
            int temp = actual->getDato();
            actual->setDato(siguiente->getDato());
            siguiente->setDato(temp);
        }

        actual = siguiente;
        siguiente = siguiente->getSiguiente();
    }

    ordenarPorDigitosRecursivo(p->getSiguiente());
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    ordenarPorDigitosRecursivo(lista.getPrimero());

    cout << "Impresion de lista ordenada por digito" << endl;
    imprimirNumeros(lista.getPrimero());

    return 0;
}
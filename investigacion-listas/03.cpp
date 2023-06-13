/**
 *  Ingresar una lista y modificar sus valores, sumando a cada uno la cantidad de dígitos que posee
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

void sumarDigitosRecursivo(Nodo *p)
{
    if (p == NULL)
    {
        return;
    }

    int dato = p->getDato();
    int digitos = contarDigitosRecursivo(dato);
    p->setDato(dato + digitos);

    sumarDigitosRecursivo(p->getSiguiente());
}

int main()
{
    Lista lista;

    ingresarNumeros(&lista);

    cout << "Impresion de lista" << endl;
    imprimirNumeros(lista.getPrimero());

    sumarDigitosRecursivo(lista.getPrimero());

    cout << "Impresion de lista despues de modificar" << endl;
    imprimirNumeros(lista.getPrimero());

    return 0;
}
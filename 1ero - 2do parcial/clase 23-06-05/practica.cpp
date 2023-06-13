/**
 * programa recursivo que permita modificar el orden de los elementos de una
 * lista ingresada, de forma que los N últimos nodos pasen a ser los primeros.
 * Autor: Andres Gaibor
 */
#include <iostream>

#include "../utilidades/lista.h"

using namespace std;

int datoDesdeEntrada(string mensaje = "Ingresar un dato")
{
    string linea;
    cout << endl
         << mensaje << " (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return NULL;
    }

    int dato = stoi(linea);

    return dato;
}

void leerLista(Lista *l)
{
    Tipo dato = datoDesdeEntrada();

    if (dato == NULL)
    {
        return;
    }

    l->insertarFinal(dato);

    leerLista(l);
}

/**
 * n es el numero de ultimos elementos en la lista
 */
// n = 4
void modOrdenLista(Lista *l, int totalN, int n, Nodo *p, Nodo *ant = NULL, Nodo *primer = NULL)
{
    int nqq = totalN - n; // 6 - 4 = 2 nodos que se quedan igual

    if (p == NULL) // Estamos al final de la lista
    {
        ant->setSiguiente(primer);
        return;
    }

    if (primer == NULL)
    { // No se ha inicializado, y lo inicializamos con el valor de primero (p)
        primer = p;
    }

    Nodo *sg = p->getSiguiente();

    if (nqq == 1)
    { // estoy en el ultimo elemento que se mantiene por lo q debe apuntar a NmULL
        p->setSiguiente(NULL);
    }

    if (nqq == 0)
    {
        l->setPrimero(p);
    }

    modOrdenLista(l, totalN - 1, n, sg, p, primer);
}

void imprimirLista(Nodo *act = NULL)
{
    if (act == NULL)
    {
        return;
    }

    cout << endl
         << "> " << act->getDato() << endl;

    imprimirLista(act->getSiguiente());
}

void imprimir(Lista l)
{
    imprimirLista(l.getPrimero());
}

void modOrden(Lista *l)
{
    int n;
    cout << "Ingresar cuantos ultimos elementos desea poner primero: ";
    cin >> n;

    Nodo *primero = l->getPrimero();

    modOrdenLista(l, l->contarNodos(primero), n, primero);
}

int main()
{
    Lista l;

    leerLista(&l);

    cout << endl
         << "Lista original " << endl;
    imprimir(l);

    modOrden(&l);

    cout << endl
         << "Lista con orden modificado " << endl;
    imprimir(l);

    return 0;
}
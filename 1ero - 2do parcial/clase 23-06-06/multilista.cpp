
#include <iostream>

#include "../../utilidades/ListaMulti.h"

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

void individualizarDigitos(int numero, MultiLista *l, NodoM *p)
{
    if (numero == 0)
    {
        return;
    }

    int dig = numero % 10;

    int d = numero / 10;

    numero = (numero - dig) / 10;

    l->insertarAbajo(dig, p);

    individualizarDigitos(numero, l, p);
}

void leerLista(MultiLista *l, NodoM *p = NULL)
{
    Tipo dato = datoDesdeEntrada("Ingrese un numero entero");

    if (dato == NULL)
    {
        return;
    }

    // l->insertarFinal(dato);
    if (p == NULL)
    {
        NodoM *nuev;
        l->setPrimero(nuev);
    }

    l->insertarFinal(0);
    individualizarDigitos(dato, l, p);

    leerLista(l, p->getSiguiente());
}

void imprimirLista(NodoM *act = NULL)
{
    if (act == NULL)
    {
        cout << endl
             << "La lista esta vacia " << endl;
        return;
    }

    cout << endl
         << "> " << act->getDato() << endl;

    // imprimirLista(act->getSiguiente());
    imprimirLista(act->getAbajo());
}

void recorrerSiguiente(NodoM *p, NodoM *primero = NULL)
{
    if (primero == NULL)
    {
        primero = p;
    }

    imprimirLista(p);

    recorrerSiguiente(p->getSiguiente());
}

void imprimir(MultiLista l)
{
    imprimirLista(l.getPrimero());
}

int main()
{
    MultiLista l;

    leerLista(&l);

    cout << endl
         << "La lista hacia abajo " << endl;
    imprimir(l);
}
#ifndef LISTAC_H
#define LISTAC_H
#include "lista.h"

class ListaCircular : public Lista
{
public:
    void insertarInicio(Tipo v);
    void insertarFinal(Tipo v);
    Nodo *ultimo();
};

Nodo *ListaCircular::ultimo()
{
    Nodo *aux = getPrimero();

    while (aux != NULL && aux->getSiguiente() != getPrimero())
    {
        aux = aux->getSiguiente();
    }

    return aux;
}

void ListaCircular::insertarInicio(Tipo v)
{
    Nodo *nuevo = new Nodo(v, getPrimero());

    if (esVacia())
    {
        nuevo->setSiguiente(nuevo);
    }
    else
    {
        ultimo()->setSiguiente(nuevo);
    }

    setPrimero(nuevo);
}

void ListaCircular::insertarFinal(Tipo v)
{
    Nodo *nuevo = new Nodo(v, getPrimero());

    if (esVacia())
    {
        nuevo->setSiguiente(nuevo);
        setPrimero(nuevo);
    }
    else
    {
        ultimo()->setSiguiente(nuevo);
    }
}

#endif
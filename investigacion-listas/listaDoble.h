#ifndef LISTAD_H
#define LISTAD_H
#include "nodoDoble.h"
#include "lista.h"

class ListaDoble : public Lista
{
public:
    ListaDoble();
    NodoDoble *getPrimero();
    void insertarInicio(Tipo v);
    void insertarFinal(Tipo v);
    NodoDoble *getAnterior(NodoDoble *actual);
};

NodoDoble *ListaDoble::getPrimero()
{
    return (NodoDoble *)Lista::getPrimero();
}

ListaDoble::ListaDoble() : Lista()
{
}

void ListaDoble::insertarInicio(Tipo v)
{
    NodoDoble *nuevo = new NodoDoble(v, getPrimero(), NULL);

    if (!esVacia())
    {
        NodoDoble *primero = getPrimero();
        primero->setAnterior(nuevo);
    }

    setPrimero(nuevo);
}

void ListaDoble::insertarFinal(Tipo v)
{
    NodoDoble *nuevo = new NodoDoble(v, NULL, NULL);

    if (esVacia())
    {
        setPrimero(nuevo);

        return;
    }

    NodoDoble *p = getPrimero();

    while (p->getSiguiente() != NULL)
    {
        p = (NodoDoble *)p->getSiguiente();
    }

    p->setSiguiente(nuevo);
    nuevo->setAnterior(p);
}

NodoDoble *ListaDoble::getAnterior(NodoDoble *ref)
{
    if (ref == NULL)
    {
        return (NodoDoble *)NULL;
    }

    return ref->getAnterior();
}

#endif
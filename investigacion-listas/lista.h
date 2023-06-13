#ifndef LISTA_H
#define LISTA_H
#define NULL __null
#include "nodo.h"

class Lista
{
private:
    Nodo *primero;

public:
    Lista();
    void setPrimero(Nodo *p);
    Nodo *getPrimero();
    bool esVacia();
    void vaciarLista();
    void insertarInicio(Tipo v);
    Nodo *ultimo();
    void insertarFinal(Tipo v);
    Nodo *buscarElemento(Tipo v);
    Nodo *getAnterior(Nodo *actual);
    bool eliminarNodo(Nodo *el);
    bool eliminarNodoPorValor(Tipo v);

    void insertarEnOrden(Tipo v);

    int contarNodos(Nodo *primero);
};

void Lista::setPrimero(Nodo *p)
{
    primero = p;
}

Lista::Lista()
{
    setPrimero(NULL);
}

Nodo *Lista::getPrimero()
{
    return primero;
}

bool Lista::esVacia()
{
    return (getPrimero() == NULL);
}

void Lista::vaciarLista()
{
    setPrimero(NULL);
}

void Lista::insertarInicio(Tipo v)
{
    Nodo *nuevo = new Nodo(v, getPrimero());
    setPrimero(nuevo);
}

Nodo *Lista::ultimo()
{
    Nodo *aux = getPrimero();

    while (aux != NULL && aux->getSiguiente() != NULL)
    {
        aux = aux->getSiguiente();
    }

    return aux;
}

void Lista::insertarFinal(Tipo v)
{
    Nodo *nuevo = new Nodo(v);

    if (esVacia())
    {
        setPrimero(nuevo);
    }
    else
    {
        ultimo()->setSiguiente(nuevo);
    }
}

Nodo *Lista::buscarElemento(Tipo v)
{
    Nodo *n = getPrimero();

    while (n != NULL && n->getDato() != v)
    {
        n = n->getSiguiente();
    }

    return n;
}

Nodo *Lista::getAnterior(Nodo *actual)
{
    Nodo *n = getPrimero();

    while (n != NULL && n->getSiguiente() != actual)
    {
        n = n->getSiguiente();
    }

    return n;
}

bool Lista::eliminarNodo(Nodo *el)
{
    if (el == NULL)
    {
        return false;
    }

    Nodo *sg = el->getSiguiente();
    Nodo *ant = getAnterior(el);

    if (ant == NULL)
    {
        setPrimero(sg);
    }
    else
    {
        ant->setSiguiente(sg);
    }

    return true;
}

bool Lista::eliminarNodoPorValor(Tipo valor)
{
    Nodo *n = buscarElemento(valor);

    if (n == NULL)
    {
        return false;
    }

    return eliminarNodo(n);
}

int Lista::contarNodos(Nodo *pNodo)
{
    if (pNodo == NULL)
    {
        return 0;
    }

    return 1 + contarNodos(pNodo->getSiguiente());
}

#endif // LISTA_H
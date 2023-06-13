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

    void invertirLista(Nodo *primero, Nodo *anterior);
    void invertirLista();

    void intercalar(Nodo *pL, Nodo *pL2, Lista *l3);
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

void Lista::insertarEnOrden(Tipo valor)
{
    Nodo *nuevo = new Nodo(valor);

    if (esVacia())
    { // 1. Si la lista esta vacio
        setPrimero(nuevo);
        return;
    }

    Nodo *p = getPrimero();

    if (valor < p->getDato())
    { // 2. Si es menor que el primero
        setPrimero(nuevo);
        nuevo->setSiguiente(p);

        return;
    }

    p = p->getSiguiente();

    Nodo *sg = p->getSiguiente();

    while (p->getSiguiente() != NULL && valor > p->getSiguiente()->getDato())
    {
        p = p->getSiguiente();
    }

    if (p == NULL)
    {
        nuevo->setSiguiente(p->getSiguiente());
    }
    nuevo->setSiguiente(p->getSiguiente());

    p->setSiguiente(nuevo);
}

int Lista::contarNodos(Nodo *pNodo)
{
    if (pNodo == NULL)
    {
        return 0;
    }

    return 1 + contarNodos(pNodo->getSiguiente());
}

// PRIMERO -> N -> N2 -> N3 -> NULL
// NULL <- N <- N2 <- N3 <- PRIMERO

//

void Lista::invertirLista(Nodo *p, Nodo *ant)
{
    if (p == NULL) // si es el ultimo nodo
    {
        setPrimero(ant);
        return;
    }

    Nodo *sg = p->getSiguiente();

    p->setSiguiente(ant);

    return invertirLista(sg, p);
}

void Lista::invertirLista()
{
    // if (esVacia())
    // {
    //     return;
    // }

    invertirLista(getPrimero(), NULL);
}

void Lista::intercalar(Nodo *pL, Nodo *pL2, Lista *l3)
{
    if (pL == NULL && pL2 == NULL)
    {
        return;
    }

    if (pL != NULL)
    {
        l3->insertarFinal(pL->getDato());
        pL = pL->getSiguiente();
    }

    if (pL2 != NULL)
    {
        l3->insertarFinal(pL2->getDato());
        pL2 = pL2->getSiguiente();
    }

    intercalar(pL, pL2, l3);
}

#endif // LISTA_H
#ifndef NODOD_H
#define NODOD_H

#include "nodo.h"

class NodoDoble : public Nodo
{
private:
    NodoDoble *anterior;

public:
    NodoDoble();
    NodoDoble(Tipo valor);
    NodoDoble(Tipo valor, NodoDoble *refSiguiente, NodoDoble *refAnterior);

    void setAnterior(NodoDoble *refAnterior);
    NodoDoble *getAnterior();
};

NodoDoble::NodoDoble() : Nodo()
{
    setAnterior(NULL);
}

NodoDoble::NodoDoble(Tipo valor) : Nodo(valor)
{
    setAnterior(NULL);
}

NodoDoble::NodoDoble(Tipo valor, NodoDoble *refSiguiente, NodoDoble *refAnterior) : Nodo(valor, refSiguiente)
{
    setAnterior(refAnterior);
}

void NodoDoble::setAnterior(NodoDoble *refAnterior)
{
    anterior = refAnterior;
}

NodoDoble *NodoDoble::getAnterior()
{
    return anterior;
}

#endif

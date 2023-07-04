/**
 * Definicion de la clase de una lista simple
 */

#ifndef NODOV_H
#define NODOV_H

// #include <cstddef>
#include "vertice.h"

typedef Vertice Tipo;

class Nodo
{
private:
    Tipo dato;
    Nodo *siguiente;

public:
    Nodo();
    Nodo(Tipo valor);
    Nodo(Tipo valor, Nodo *refSiguiente);

    void setDato(Tipo valor);
    Tipo getDato();

    void setSiguiente(Nodo *refSiguiente);
    Nodo *getSiguiente();
};

Nodo::Nodo()
{
    setSiguiente(NULL);
}

Nodo::Nodo(Tipo valor) : Nodo()
{
    setDato(valor);
}

Nodo::Nodo(Tipo valor, Nodo *refSiguiente) : Nodo(valor)
{
    setSiguiente(refSiguiente);
}

void Nodo::setDato(Tipo valor)
{
    dato = valor;
}

Tipo Nodo::getDato()
{
    return dato;
}

void Nodo::setSiguiente(Nodo *refSiguiente)
{
    siguiente = refSiguiente;
}

Nodo *Nodo::getSiguiente()
{
    return siguiente;
}

#endif

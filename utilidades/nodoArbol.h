/**
 * Definicion de la clase de una lista simple
 */
typedef int Tipo;

#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

#include <cstddef>

typedef int Tipo;

class NodoBinario
{
private:
    Tipo dato;
    NodoBinario *padre, *izq, *der;

public:
    NodoBinario();
    NodoBinario(Tipo dato);
    NodoBinario(Tipo dato, NodoBinario* hIzq, NodoBinario* hDer);

    void setDato(Tipo valor);

    void setPadre(NodoBinario* ref);
    void setHijoIzquierdo(NodoBinario* ref);
    void setHijoDerecho(NodoBinario* ref);

    Tipo getDato();

    NodoBinario* getPadre();
    NodoBinario* getHijoIzquierdo();
    NodoBinario* getHijoDerecho();

};

NodoBinario::NodoBinario()
{
    setPadre(nullptr);
    setHijoIzquierdo(nullptr);
    setHijoDerecho(nullptr);
}

NodoBinario::NodoBinario(Tipo dato): NodoBinario()
{
    setDato(dato);
}

NodoBinario::NodoBinario(Tipo dato, NodoBinario* hIzq, NodoBinario* hDer)
{
    setDato(dato);

    setPadre(nullptr);
    setHijoIzquierdo(hIzq);
    setHijoDerecho(hDer);
}

void NodoBinario::setDato(Tipo valor) {
    dato = valor;
}

Tipo NodoBinario::getDato() {
    return dato;
}

void NodoBinario::setPadre(NodoBinario* ref) {
    padre = ref;
}
void NodoBinario::setHijoIzquierdo(NodoBinario* ref) {
    izq = ref;
    if(ref != nullptr) {
        ref->setPadre(this);
    } 
}
void NodoBinario::setHijoDerecho(NodoBinario* ref) {
    der = ref;
    if(ref != nullptr) {
        ref->setPadre(this);
    } 
}

NodoBinario* NodoBinario::getPadre() {
    return padre;
}
NodoBinario* NodoBinario::getHijoIzquierdo() {
    return izq;
}
NodoBinario* NodoBinario::getHijoDerecho() {
    return der;
}

#endif

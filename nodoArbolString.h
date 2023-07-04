/**
 * Definicion de nodo para arboles binarios de busqueda
 */

#ifndef NODO_ARBOLS_H
#define NODO_ARBOLS_H

#include <cstddef>
#include <string>

using namespace std;

typedef string Tipo;

int charToAscii(char c)
{
    return (int)c;
}

int stringToAscii(string s)
{
    int suma = 0;

    for (int i = 0; i < s.length(); i++)
    {
        suma += tolower(charToAscii(s[i]));
    }

    return suma;
}

class NodoBinario
{
private:
    Tipo dato;
    NodoBinario *padre, *izq, *der;

public:
    NodoBinario();
    NodoBinario(Tipo dato);
    NodoBinario(Tipo dato, NodoBinario *hIzq, NodoBinario *hDer);

    void setDato(Tipo valor);

    void setPadre(NodoBinario *ref);
    void setHijoIzquierdo(NodoBinario *ref);
    void setHijoDerecho(NodoBinario *ref);

    Tipo getDato();

    NodoBinario *getPadre();
    NodoBinario *getHijoIzquierdo();
    NodoBinario *getHijoDerecho();
};

NodoBinario::NodoBinario()
{
    setPadre(nullptr);
    setHijoIzquierdo(nullptr);
    setHijoDerecho(nullptr);
}

NodoBinario::NodoBinario(Tipo dato) : NodoBinario()
{
    setDato(dato);
}

NodoBinario::NodoBinario(Tipo dato, NodoBinario *hIzq, NodoBinario *hDer)
{
    setDato(dato);

    setPadre(nullptr);
    setHijoIzquierdo(hIzq);
    setHijoDerecho(hDer);
}

void NodoBinario::setDato(Tipo valor)
{
    dato = valor;
}

Tipo NodoBinario::getDato()
{
    return dato;
}

void NodoBinario::setPadre(NodoBinario *ref)
{
    padre = ref;
}
void NodoBinario::setHijoIzquierdo(NodoBinario *ref)
{
    izq = ref;
    if (ref != nullptr)
    {
        ref->setPadre(this);
    }
}
void NodoBinario::setHijoDerecho(NodoBinario *ref)
{
    der = ref;
    if (ref != nullptr)
    {
        ref->setPadre(this);
    }
}

NodoBinario *NodoBinario::getPadre()
{
    return padre;
}
NodoBinario *NodoBinario::getHijoIzquierdo()
{
    return izq;
}
NodoBinario *NodoBinario::getHijoDerecho()
{
    return der;
}

#endif

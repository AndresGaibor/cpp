/**
 * Definicion de la clase de una lista simple
 */

#ifndef VERTICE_GRAFO2_H
#define VERTICE_GRAFO2_H

typedef std::string TipoG;

#include <cstddef>

using namespace std;

class Vertice
{
private:
    TipoG dato;
    int num;

public:
    Vertice();
    Vertice(TipoG dato);
    Vertice(TipoG dato, int num);

    void setDato(TipoG valor);
    void setNum(int num);
    bool esIgualDato(TipoG valor);

    TipoG getDato();
    int getNum();
};

bool Vertice::esIgualDato(TipoG valor)
{
    return dato == valor;
}

Vertice::Vertice()
{
    setNum(-1);
}

Vertice::Vertice(TipoG dato) : Vertice()
{
    setDato(dato);
}

Vertice::Vertice(TipoG dato, int num) : Vertice(dato)
{
    setNum(num);
}

void Vertice::setDato(TipoG valor)
{
    dato = valor;
}

void Vertice::setNum(int num)
{
    this->num = num;
}

TipoG Vertice::getDato()
{
    return dato;
}

int Vertice::getNum()
{
    return num;
}

#endif

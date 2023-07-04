/**
 * Definicion de la clase de una lista simple
 */



#ifndef VERTICE_GRAFO_H
#define VERTICE_GRAFO_H

typedef string Tipo;

#include <cstddef>

using namespace std;

class Vertice {
private:
    Tipo dato;
    int num;
public:
    Vertice();
    Vertice(Tipo dato);
    Vertice(Tipo dato, int num);

    void setDato(Tipo valor);
    void setNum(int num);
    bool esIgualDato(Tipo valor);

    Tipo getDato();
    int getNum();
};

bool Vertice::esIgualDato(Tipo valor) {
    return dato == valor;
}

Vertice::Vertice() {
    setNum(-1);
}

Vertice::Vertice(Tipo dato): Vertice() {
    setDato(dato);
}

Vertice::Vertice(Tipo dato, int num): Vertice(dato) {
    setNum(num);
}

void Vertice::setDato(Tipo valor) {
    dato = valor;
}

void Vertice::setNum(int num) {
    this->num = num;
}

Tipo Vertice::getDato() {
    return dato;
}

int Vertice::getNum() {
    return num;
}

#endif

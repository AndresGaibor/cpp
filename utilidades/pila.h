// required iostream

#include <iostream>

using namespace std;


#ifndef PILA_H

#define EXT 100
typedef int Tipo;

class Pila {
    private:
        Tipo vector[EXT];
        int tope;
        
        void setVector(int i, Tipo dato);
        Tipo getVector(int i);
        bool estaVacia();
        bool estaLlena();
        void setTope(int tope);
        int getTope();
    public:
        Pila();
        
        void push(Tipo dato);
        int pop();
};

Pila::Pila() {
    tope = -1;
}

void Pila::setVector(int i, Tipo dato) {
    vector[i] = dato;
}

Tipo Pila::getVector(int i) {
    return vector[i];
}

void Pila::setTope(int dato) {
    tope = dato;
}

int Pila::getTope() {
    return tope;
}

bool Pila::estaVacia() {
    return tope == -1;
}

bool Pila::estaLlena() {
    return tope == EXT - 1;
}

void Pila::push(Tipo valor) {
    if(!estaLlena()) {
        tope++;
        vector[tope] = valor;
    } else {
        cout << "La pila esta llena" << endl;
    }
}

Tipo Pila::pop() {
    Tipo valor = -1;
    if(!estaVacia()) {
        valor = vector[tope];
        tope--;
    }
    return valor;
}



#endif // PILA_H
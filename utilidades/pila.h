// required iostream

#include <iostream>
#include <string>

using namespace std;


#ifndef PILA_H

#define EXT 100

typedef int Tipo; // Definir el tipo por defecto si no está definido previamente

class Pila {
    private:
        Tipo vector[EXT];
        int tope;
        
        void setVector(int i, Tipo dato);
        Tipo getVector(int i);

        void setTope(int tope);
        void mostrarPila(Pila p);
    public:
        Pila();
        int getTope();
        bool isEmpty();
        bool isFull();
        
        bool CanPush();
        bool CanPop();

        void push(Tipo dato);
        int pop();

        void vaciarPila();
        int longitudPila();
        Tipo cimaPila();

        void leer();
        void mostrar();

        int contarNodos();
};


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


Pila::Pila() {
    setTope(-1);
}

bool Pila::isEmpty() {
    return getTope() == -1;
}

bool Pila::isFull() {
    return getTope() == EXT - 1;
}

void Pila::push(Tipo valor) {
    if(isFull()) {
        cout << "La pila esta llena" << endl;
        return;
    }

    setTope(getTope()+1);

    setVector(getTope(), valor);

}

Tipo Pila::pop() {
    Tipo valor;

    if(!isEmpty()) {
        valor = getVector(getTope());

        setTope(getTope()-1);
    }

    return valor;
}

void Pila::vaciarPila() {
    setTope(-1);
}

int Pila::longitudPila() {
    return getTope() + 1;
}

Tipo Pila::cimaPila() {
    if(!isEmpty()) {
        return getVector(getTope());
    } else {
        return -1;
    }
}

bool Pila::CanPush() {
    return isFull() == false;
}

void Pila::leer() {
   if (isFull()) {
        cout << endl << "La pila esta llena";
        return;
    }

    string linea;
    cout << endl << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty()) {
        return;
    }

    int dato = stoi(linea);
    
    push(dato);

    leer();
}

bool Pila::CanPop() {
    return isEmpty() == false;
}

void Pila::mostrarPila(Pila p) {
    if (p.isEmpty()) {
        return;
    }     

    if(CanPop()) {
        cout << endl << "Elemento [" << p.getTope() << "]: " << p.pop();
    } else {
        cout << endl << "No se puede desencolar (fila vacia)";
    }

    mostrarPila(p);
}

void Pila::mostrar() {
    mostrarPila(*this);
}

#endif // PILA_H
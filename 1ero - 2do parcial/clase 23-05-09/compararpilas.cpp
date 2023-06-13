/**
 * Programa que permita el ingreso de 2 pilas, y verificar si son iguales
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

void leerPila(Pila *p) {
    Tipo fin = 99999;
    Tipo valor;

    do {
        cout << endl << "Ingrese un a apilar. finalice con " << fin << ": ";
        cin >> valor;

        if(valor == fin) {
            continue;
        }
        
        if((*p).estaLlena()) {
            cout << endl << "Ya esta llena la pila";
            valor = fin;
            continue;
        }

        (*p).push(valor);

    } while(valor != fin);
}

void mostrarPila(Pila *p) {
    cout << endl  << "ELEMENTOS CONTENIDOS EN LA PILA" << endl;
    
    while(!(*p).estaVacia()) {
        int i = (*p).longitudPila();
        Tipo elemento = (*p).pop();

        cout << endl << "[" << i << "] > " << elemento; 
    }
}

bool sonIguales(Pila p1, Pila p2) {
    if(p1.longitudPila() != p2.longitudPila()) {
        return false;
    }

    if(p1.estaVacia()) {
        return true;
    }

    if(p1.pop() != p2.pop()) {
        return false;
    }

    return sonIguales(p1, p2);
}

int main() {
    Pila p;
    Pila q;

    leerPila(&p);
    leerPila(&q);
    
    cout << "Son " << (sonIguales(p, q) ? "iguales": "diferentes");

    mostrarPila(&p);
    mostrarPila(&q);
}
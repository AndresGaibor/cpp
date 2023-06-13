/**
 * Programa que permite el ingreso y visualizacion de datos en una pila
 * 
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

int main() {
    Pila p;

    leerPila(&p);
    mostrarPila(&p);
}
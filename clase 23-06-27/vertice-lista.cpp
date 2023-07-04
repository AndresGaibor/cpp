/**
 * Archivo de grafo
 * Autor: Andres Gaibor
*/

#include <iostream>
#include <string>
#include "../utilidades/listaVertice.h"

using namespace std;

void leerVertice(Lista *lista, int n) {
    if(n == 0) {
        return;
    }
    
    leerVertice(lista, n - 1);

    string linea;
    cout << endl << "Ingrese valor para el vertice (Presione Enter para dejar de ingresar): ";
    cin >> linea;

    lista->insertarFinal(linea);
}

void imprimirVertice(Nodo *p) {
    if(p == NULL) {
        return;
    }


    imprimirVertice(p->getSiguiente());

    cout << "Vertice " < endl;

    cout << endl << "El valor: " << p->getDato().getDato();
    cout << endl << "El numero: " << p->getDato().getNum();
}

int leerN() {
    int n;
    cout << endl << "Ingrese el numero de vertices: ";
    cin >> n;
    
    return n;
}

bool buscarVerticePorDato(Nodo *p, string dato) {
    if(p == nullptr) {
        return false;
    }

    if(p.getDato().getDato() == dato) {
        // cout << "Se encontro el vertice con el dato " << dato << " en la posicion " << n - 1 << endl;
        return true;
    }

    buscarVerticePorDato(p->getSiguiente(), dato);

}

void buscarVertice(Lista *lis) {
    int cant;

    cout << endl << "La cantidad de busquedas que desea realizar: ";
    cin >> cant;

    string dato;

    for(int i = 0; i < cant; i++) {
        cout << endl << "Ingrese el dato a buscar: ";
        cin >> dato;

        bool encontrado = buscarVerticePorDato(lis->getPrimero(), dato);

        cout << endl << (encontrado ? "Si" : "No") << " se encontro el vertice" << endl;
    }
}

int main() {
    Lista *lista;

    cout << endl << "CANTIDAD DE VERTICES A PROCESAR" << endl;
    int n = leerN();

    leerVertice(lista, n);

    imprimirVertice(lista, n);

}
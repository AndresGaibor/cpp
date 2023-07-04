/**
 * Archivo de grafo
 * Autor: Andres Gaibor
*/

#include <iostream>
#include <string>
#include "../utilidades/vertice.h"

using namespace std;

void leerVertice(Vertice vec[], int n) {
    if(n == 0) {
        return;
    }
    
    leerVertice(vec, n - 1);

    string linea;
    cout << endl << "Ingrese valor para el vertice (Presione Enter para dejar de ingresar): ";
    cin >> linea;
    vec[n - 1].setDato(linea);
    vec[n - 1].setNum(n - 1);

}

void imprimirVertice(Vertice vec[], int n) {
    if(n == 0 ) {
        return;
    }

    imprimirVertice(vec, n - 1);

    cout << endl << endl << "Vertice " << n - 1 << endl;
    
    cout << endl << "El valor: " << vec[n - 1].getDato();
    cout << endl << "El numero: " << vec[n - 1].getNum();
}

int leerN() {
    int n;
    cout << endl << "Ingrese el numero de vertices: ";
    cin >> n;
    
    return n;
}

bool buscarVerticePorDato(Vertice vec[], int n, string dato) {
    if(n == 0) {
        return false;
    }

    if(vec[n - 1].getDato() == dato) {
        // cout << "Se encontro el vertice con el dato " << dato << " en la posicion " << n - 1 << endl;
        return true;
    }

    buscarVerticePorDato(vec, n - 1, dato);

}

void buscarVertice(Vertice vec[], int n) {
    int cant;

    cout << endl << "La cantidad de busquedas que desea realizar: ";
    cin >> cant;

    Tipo dato;

    for(int i = 0; i < cant; i++) {
        cout << endl << "Ingrese el dato a buscar: ";
        cin >> dato;

        bool encontrado = buscarVerticePorDato(vec, n, dato);

        cout << endl << (encontrado ? "Si" : "No") << " se encontro el vertice" << endl;
    }
}

int main() {
    Vertice *vector;

    cout << endl << "CANTIDAD DE VERTICES A PROCESAR" << endl;
    int n = leerN();

    vector = new Vertice[n];

    leerVertice(vector, n);

    imprimirVertice(vector, n);

}
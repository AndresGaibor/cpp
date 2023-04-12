/*
    Programa para la gestion basica de arreglos.
    Autor: Andres Gaibor Apunte.
    Codigo: 7255
*/

#include <iostream>
#include <cstdlib>
#include <string>

#define EXT 10

using namespace std;

int leerNumero(int limitSuperior, int limitInferior = 1, bool pos = false) {
    int numero;

    do {
        if(pos) {
            cout << "Ingrese la posicion del numero (" << limitInferior << " ... " << limitSuperior << "): ";
        } else {
            cout << "Ingresa el numero de elementos del arreglo (max " << limitSuperior << "): ";
        }

        cin >> numero;
    } while(numero < limitInferior || numero > limitSuperior);

    return numero;
}

void mostrarPosition(int i) {
    cout << endl << "Posicion [" << i << "]: ";
}

void leerArreglo(int *arreglo, int n) {
    cout << endl << "Lectura del arreglo" << endl;
    for(int i = 0; i < n; i++) {
        mostrarPosition(i);
        
        cin >> *(arreglo + i);
    }
    cout << endl;
}

void mostrarArreglo(int arreglo[], int n) {
    cout << endl << "Mostrando el arreglo" << endl;
    for(int i = 0; i < n; i++) {
        mostrarPosition(i);
        cout << arreglo[i];
    }
    cout << endl;
}

bool leerRemplazar() {
    bool rem = false;

    string opt;
    cout << "Desea remplazar el valor actual de esa posicion (si o no) :"; cin >> opt;

    if(opt == "si") { rem = true; }

    return rem;
}

void liberarPos(int arreglo[], int n, int pos) {
    for (int i = n; i > pos; i--) {
        arreglo[i] = arreglo[i - 1]; // ESTO LIBERA EL ELEMENTO DE LA POS, DESPLAZANDO LOS DEMAS HACIA LA DERECHA
    }
}

void eliminarPos(int arreglo[], int n, int pos) { 
    for (int i = pos; i < n; i++) {
        arreglo[i] = arreglo[i + 1];
    }
}

int inserccion(int arreglo[], int n) {
    int nnumero, pos; 
    cout << endl << "Ingresar un nuevo numero: "; cin >> nnumero; cout << endl;

    pos = leerNumero(n, 0, true);

    bool remplazar = leerRemplazar();

    if(!remplazar) { // SI REMPLAZAR ES FALSO ENTONCES EJECUTA ESTO
        n++;

        liberarPos(arreglo, n, pos);
    }

    arreglo[pos] = nnumero;

    return n;
}

int buscarEl(int arreglo[], int n) {
    int el, pos = -1;
    cout << endl << "Ingrese el valor a buscar en el arreglo: "; cin >> el;

    for (int i = 0; i < n; i++) {
        if (arreglo[i] == el) {
            pos = i;
            i = n; // TERMINA EL CICLO FOR
        }
    }

    return pos;
}

int eliminarElPorPosicion(int arreglo[], int n, int pos = -1) {
    cout << endl << "Eliminando elemento " << endl;
    if(pos == -1) {
        pos = leerNumero(n - 1, 0, true);
    }

    n--;

    eliminarPos(arreglo, n, pos);
    
    return n;
}

int eliminarElementoBuscar(int arreglo[], int n) {
    int posEl = buscarEl(arreglo, n);

    cout << "pos " << posEl;

    if(posEl != -1) {
        return eliminarElPorPosicion(arreglo, n, posEl);
    } else {
        cout << endl << "No se encontro el elemento " << endl;
    }
    
    return n;
}

int main() {
    int n = leerNumero(EXT);

    int arreglo[EXT*10];

    leerArreglo(arreglo, n);

    mostrarArreglo(arreglo, n);

    n = inserccion(arreglo, n);

    mostrarArreglo(arreglo, n);

    n = eliminarElPorPosicion(arreglo, n);

    mostrarArreglo(arreglo, n);

    n = eliminarElementoBuscar(arreglo, n);

    mostrarArreglo(arreglo, n);

    system("read -p 'Press Enter to continue...' var");

    return 0;
}


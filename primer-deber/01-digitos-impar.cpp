/**
 *   Autor: Andres Gaibor Apunte.
 *   Codigo: 7255
 *   Ejercicio:
 * Generar un listado ordenado descendentemente con los valores que contienen una 
 * cantidad impar de dígitos, tomados de entre varios números enteros ingresados por 
 * el usuario (aplíquese el algoritmo de ordenamiento por inserción)
*/

#include <iostream>

using namespace std;

#define MAX 100

int leerNumero(int max, int min = 1) {
    int numero;
    do {
        cout << "Ingrese el numero de elementos ( " << min << " ... " << max << " ): ";
        cin >> numero; 
    } while (numero < min | numero > max);

    return numero;
}

void leerArreglo(int arreglo[], int n) {
    cout << endl << "Ingreso de elementos " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
}

int numeroDigitos(int a) {
    int conta = 1;
    int divi = 10;

    while(a != (a % divi)) {
        divi = divi * 10;
        conta++;
    }

    return conta;
} 

int filtrarImpares(int arreglo[], int n) {
    int nImpares = n;
    for (int i = n-1; i >= 0; i--) {
        int a = arreglo[i];
        if (numeroDigitos(a) % 2 == 0) {
            for (int j = i; j < nImpares-1; j++) {
                arreglo[j] = arreglo[j+1];
            }
            nImpares--;
        }
    }
    return nImpares;
}

int buscarPosMenor(int b, int pos, int arreglo[]) {
    int menor = numeroDigitos(b), posMenor = pos;

    for(int i = pos - 1; i >= 0; i--) {
        int izq = numeroDigitos(arreglo[i]);

        if(menor > izq) {
            menor = izq;
            posMenor = i;
        }
    }

    return posMenor;
}

void ordernarInsercion(int arreglo[], int n) {
    for(int i = 1; i < n; i++) {
        int b = arreglo[i];

        int posMenor = buscarPosMenor(b, i, arreglo);
        
        for(int j = i; j > posMenor; j--) { // desplazar desde la posicion k hacia la derecha
            arreglo[j] = arreglo[j-1];
        }

        arreglo[posMenor] = b;
    }
}

void mostrarArreglo(int arreglo[], int n) {
    cout << endl << "Mostrar los elementos " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: " << arreglo[i] << endl;
    }
}

int main() {
    int arreglo[MAX];

    int n = leerNumero(MAX);

    leerArreglo(arreglo, n);

    n = filtrarImpares(arreglo, n);

    ordernarInsercion(arreglo, n);

    mostrarArreglo(arreglo, n);

    return 0;
}
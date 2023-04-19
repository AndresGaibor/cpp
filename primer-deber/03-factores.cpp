/**
 *   Autor: Andres Gaibor Apunte.
 *   Codigo: 7255
 *   Ejercicio: 
 * Generar los factores primos de cada uno de varios números ingresados por el usuario 
 * (aplique el algoritmo de búsqueda binaria y ordenamiento por el método de la burbuja, 
 * en caso de requerirlo)
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

void ordernarBurbuja(int arreglo[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            int a = arreglo[j];
            int b = arreglo[j+1];
            if(a > b) {
                arreglo[j+1] = a;
                arreglo[j] = b;
            }
        }
    }
}

void factoresPrimos(int arreglo[], int n) {
    cout << endl << "Los factores primos de cada numero son: " << endl;

    for(int i = 0; i < n; i++) {
        int el = arreglo[i]; // 88

        cout << "Elemento [" << i << "]: " << el << " = 1 x ";

        for(int j = 2; j < el; j++) {
            if(el % j == 0) {
                cout << j << " x ";
                el /= j;
            }
        }

        cout << arreglo[i] << endl;

        cout << endl;
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

    ordernarBurbuja(arreglo, n);

    mostrarArreglo(arreglo, n);

    factoresPrimos(arreglo, n);

    return 0;
}
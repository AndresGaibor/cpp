/**
 *   Autor: Andres Gaibor Apunte.
 *   Codigo: 7255
 *   Ejercicio:
 * Permitir el ingreso de dos arreglos de valores enteros, y calcular la unión 
 * de los mismos (aplique método de búsqueda lineal y ordenamiento por selección en caso de requerirlos)
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

void ordernarSeleccion(int arreglo[], int n) {
    for(int i = 0; i < n; i++) {
        int a = arreglo[i];

        for(int j = i + 1; j < n; j++) {
            int b = arreglo[j];

            if(b < a) {
                arreglo[j] = a;

                a = b;
            }
        }

        arreglo[i] = a;
    }
}

int unirArreglos(int arreglo[], int arreglo2[], int n, int n2) {
    for(int i = 0; i < n2; i++) {
        arreglo[n + i] = arreglo2[i];
    }

    return n + n2;
}

void mostrarArreglo(int arreglo[], int n) {
    cout << endl << "Mostrar los elementos " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: " << arreglo[i] << endl;
    }
}

int main() {
    int arreglo[MAX];
    int arreglo2[MAX];

    cout << endl << "Ingreso de elementos del primer arreglo " << endl;
    int n = leerNumero(MAX);
    leerArreglo(arreglo, n);

    cout << endl << "Ingreso de elementos del segundo arreglo " << endl;
    int n2 = leerNumero(MAX);
    leerArreglo(arreglo2, n);

    n = unirArreglos(arreglo, arreglo2, n, n2);

    ordernarSeleccion(arreglo, n);

    mostrarArreglo(arreglo, n);

    return 0;
}
/**
 *   Autor: Andres Gaibor Apunte.
 *   Codigo: 7255
 *   Ejercicio:
 * Ingresar varios números enteros, y determinar el (los) valor(es) más repetido(s) 
 * que constan entre ellos (aplique el algoritmo de búsqueda  binaria y ordenamiento 
 * por selección, en caso de requerirlo)
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

void valorMasRepetido(int arreglo[], int n) {
    int elRep = -1;
    int veces = 0;

    for(int i = 0; i < n; i++) {
        int el = arreglo[i];

        int contador = 1;

        for(int j = i + 1; j < n; j++) {
            if(arreglo[j] != el) {
                i = j;
                break;
            }

            contador++;
        }

        if(contador > veces) {
            veces = contador;
            elRep = el;
        }

    }

    cout << "El valor mas repetido es el [" << elRep << "] " << veces << " veces" << endl;
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

    ordernarSeleccion(arreglo, n);

    mostrarArreglo(arreglo, n);

    valorMasRepetido(arreglo, n);

    return 0;
}
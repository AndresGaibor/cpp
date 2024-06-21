// Andres Gaibor 7255

// Agregar elemento a un vector ordenado
#include <iostream>

using namespace std;
int op = 0;

void insertarElemento(int vector[], int* n, int elementoNuevo) {    // n + 1 + n^2 +1+1+1+1+1 = O(n)
    int i = 0;
    while(i < *n) { //                                               ->   O(n)
        // buscamos un elemento que sea
        // ej: vector[i] = 5 y nuevoElemento = 4
        if(vector[i] >= elementoNuevo) { //                          ->   O(1)
            // desplazamos los elementos del vector desde i
            // hacia la derecha 1 posicion
            for(int j = *n; j > i; j--) {//                          ->   O(2)
                vector[j] = vector[j - 1];//                         ->   O(1)
            }
            // e insertamos el elemento en la posicion i
            vector[i] = elementoNuevo; //                            ->   O(1)
            break; //                                                ->   O(1)
        }
        // Si estamos en el ultimo elemento del vector
        // entonces ingresamos el elemento nuevo en la posicion n
        if(i + 1 == *n) { //                                         ->   O(1)
            vector[*n] = elementoNuevo; 
        }
        i++;//                                                       ->   O(1)
    }
    *n=*n+1;
}

int main() {
    int elementos[100] = { 11, 12, 13, 14, 15, 17 };
    int n = 6;
    insertarElemento(elementos, &n, 16);

    for(int i = 0; i<n; i++) {
        cout << elementos[i] << endl;
    }

    cout << endl << "operaciones" << op;
}
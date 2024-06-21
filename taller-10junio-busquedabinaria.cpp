// Taller en clase de calculo de complejidad algoritmica y temporal
// Integrantes:
// - Andres Gaibor Apunte - 7255
// - Jonathan Lizano - 7262
// - Josue Pinargote - 7120
// - Omar Figueroa - 7253

#include <iostream>

using namespace std;


int* ordenamientoBubbleSort(int vector[], int n) {  // Complejidad algoritmica O(n^2)
    for(int i = 0; i < n; i++) { //                      O(n)
        for(int j = 0; j < n - 1; j++) { //              O(n)
            if(vector[j] > vector[j + 1]) { //            O(1)
                int aux = vector[j]; //                    O(1)
                vector[j] = vector[j + 1]; //              O(1)
                vector[j + 1] = aux; //                    O(1)
            }
        }
    }

    return vector;

}

// DATOS de tabla
// n | pasos
// 1 | 1
// 2 | 2
// 3 | 2
// 4 | 3
// 5 | 3
// 6 | 3
// 7 | 3
// 8 | 4
// 9 | 4
// 10 | 4
// 11 | 4
// 12 | 4
// 13 | 4
// 14 | 4
// 15 | 4
// 16 | 5
// 17 | 5
// 18 | 5
// 19 | 5
// 20 | 5

// Mediante la grafica de la funcion en de busqueda binaria se puede
// determinar que la complejidad es logaritmica
int buscarBinaria(int valor, int arreglo[], int n) { // Complejidad algoritmica O(log n)
    int posInit, posFin, posMed; //                     O(1)

    posInit = 0; //                                     O(1)
    posFin = n - 1; //                                  O(1)

    // Aqui es log n, porque se divide el arreglo en dos en cada iteracion del
    // ciclo
    while(posInit <= posFin) { //                       O(log n)
        posMed = (posInit + posFin) / 2; //             O(1)
 
        if(arreglo[posMed] == valor) {  //              O(1)
            return posMed; //                           O(1)
        } //                                            O(1)

        if(arreglo[posMed] > valor) { //                O(1)
            posFin = posMed - 1;
            continue;
        } 
        
        posInit = posMed + 1;
    }

    return -1;
}

// Como la complejidad algoritmica de la funcion de ordenamiento bubble sort es O(n^2)
// y es mayor a la complejidad algoritmica de la funcion de busqueda binaria que es O(log n)
// por lo tanto la complejidad temporal del algoritmo es O(n^2)
int main() {    // Complejidad temporal es O(n^2) + O(log n) = O(n^2)
    // int datos[] = { 10, 20, 30, 40, 50, 60, 70 };
    int datos[] = { 50, 40, 20, 10, 30, 60, 80, 90, 100, 110, 70 };
    int n = 10;
    int target = 70;

    int* datosOrdenados = ordenamientoBubbleSort(datos, n);     // O(n^2)

    int buscarValor = buscarBinaria(target, datosOrdenados, n); // O(log n)

    cout << "Pasos: " << pasos << endl;

    if(buscarValor == -1) {
        cout << "No se encontro el valor en el vector";
    } else {
        cout << "Se encontre el valor en la posicion " << buscarValor;
    }
}
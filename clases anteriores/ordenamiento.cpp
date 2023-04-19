#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int arreglo[], int start, int end) {

}

int buscarBinaria(int valor, int arreglo[], int n) {
    int posInit, posFin, posMed;

    posInit = 0;
    posFin = n - 1;

    while(posInit <= posFin) {
        posMed = (posInit + posFin) / 2;

        if(arreglo[posMed] == valor) {
            return posMed;
        }

        if(arreglo[posMed] > valor) {
            posFin = posMed - 1;
            continue;
        } 
        
        posInit = posMed + 1;
    }

    return -1;
}

int main() {
    int arreglo[] = {5, 6, 40, 3, 2, 1, 60, 7, 7, 1, 3, 9, 2, 13, 55};
    int arregloOrdenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int n2 = sizeof(arregloOrdenado) / sizeof(arregloOrdenado[0]);

    int enc = buscarBinaria(15, arregloOrdenado, n2);
    int enc2 = buscarBinaria(5, arregloOrdenado, n2);
    int enc3 = buscarBinaria(40, arregloOrdenado, n2);

    cout << "enc " << enc << endl;
    cout << "enc2 " << enc2 << endl;
    cout << "enc3 " << enc3 << endl;



    return 0;
}
#include <iostream>

using namespace std;

// [ 8, 4, 9, 3, 5, 7, 1, 6, 2 ] 
int* quickSort(int vector[], int primero, int ultimo) {
    int i = primero; // ta
    int j = ultimo; // ta
    int medio = (vector[i] + vector[j]) / 2;  // ta 2to

    while (i < j) { // tc
        while (vector[i] < medio) { // tc
            i+=1; // to ta
        } // tc

        while (vector[j] > medio) { //tc
            j-=1; // to ta
        } // tc

        if(i <= j) {
            int aux = vector[j];
            vector[j] = vector[i];
            vector[i] = aux;

            i+=1;
            j-=1;
        }
    }

    if(primero < j) {
        vector = quickSort(vector, primero, j);
    }

    if(ultimo > i) {
        vector = quickSort(vector, i, ultimo);
    }

    return vector;
}

// [ 8, 4, 9, 3, 5, 7, 1, 6, 2 ] 
//               ij
//            j     i
// L1 = [ 8, 9, 7, 6 ]
// L2 = [ 5 ]
// L3 = [ 1, 2, 4, 3 ]
void ordenar(int arr[], int cantidad) {
    int pos_medio = cantidad / 2;
    int pivote = cantidad - 1;

    int l1

}

int main() {
    int arr[] = {5, 3, 2, 1, 4};
    int cantidad = 5;

    ordenar(arr, cantidad);

    for(int i = 0; i < cantidad; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
/**
* Ingresar tres números, y proceder a ordenarlos (ascendente o descendentemente, 
* de acuerdo a lo requerido por el usuario)
* Autor: Andres Gaibor
*/

#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int aux = *b;
    *b = *a;
    *a = aux;
}

void ordenar(int *a, int *b, int *c, int ord = 1) {
    bool s = false;

    if(*a * ord > *b * ord) {
        swap(a, b); s = true;
    }

    if(*b * ord > *c * ord) {
        swap(b, c); s = true;
    }

    if(*a * ord > *c * ord) {
        swap(a, c); s = true;
    }

    if(s) { ordenar(a, b, c, ord); }

}

int main() {
    int n1, n2, n3, orden = 1;
    cout << "Ingresar 3 numeros";
    cout << endl << "numero 1: ";
    cin >> n1;
    cout << endl << "numero 2: ";
    cin >> n2;
    cout << endl << "numero 3: ";
    cin >> n3;

    cout << endl << "Ordenar (Ingrese 1 para ASC y -1 para DESC): " ;
    cin >> orden;

    ordenar(&n1, &n2, &n3, orden);

    cout << endl << "Los numeros ordenados son " << n1 << ", " << n2 << ", " << n3;

    return 0;
}
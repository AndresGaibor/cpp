#include <iostream>

using namespace std;

int main() {
    int arreglo[5] = {1, 2, 3, 4, 5};

    int *p;

    p = &arreglo[0];

    cout << "Valor de p: " << *p << endl;
    cout << "Direccion de memoria de p: " << p << endl;
    cout << "Direccion de memoria de p + 1" << p + 1 << endl;
    cout << "Valor de p+1: " << *(p + 1) << endl;
    cout << "Direccion de memoria del apuntador p: " << &p << endl;

    return 0;
}
/**
 * Un programa que permite determinar cuantas combinaciones hay en una cadena de n bits
 * y que cumpla una condicion dada, por ejemplo que no exista 3 111 seguidos,
 * o en otro caso que no empieze con 01
*/

#include <iostream>

using namespace std;

int combinaciones(int n) {
    if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 3;
    } else {
        return combinaciones(n - 1) + combinaciones(n - 2);
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de bits: ";
    cin >> n;

    cout << "El numero de combinaciones es: " << combinaciones(n) << endl;

    return 0;
}
#include <iostream>

using namespace std;

void algoritmo(int n) {
    int contador = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            contador++;
        }
    }
    cout << "n = " << n << ", pasos = " << contador << endl;
}

int main() {
    algoritmo(0);
    algoritmo(1);
    algoritmo(2);
    algoritmo(3);
    algoritmo(4);
    algoritmo(5);
    algoritmo(6);
    algoritmo(7);
    algoritmo(8);
    algoritmo(9);
}
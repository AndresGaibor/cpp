#include <iostream>

using namespace std;

int square(int num, int val = 1) {
    while(val*val < num) {
        val++;
    }

    return val;
}

int squareRecur(int num, int val = 1) {
    int a = val*val;
    if(a < num) {
        return squareRecur(num, val + 1);
    }

    return a;
}

/**
 * Obtener los 10 primeros enteros positivos
*/
void generarNumeros(int n) {
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
    }
}

int generarNumerosRecursivo(int n, int i = 1) {
    cout << i << " ";
    int contador = i;
    
    if(i < n) {
        int rec = generarNumerosRecursivo(n,i + 1);

        contador += rec;

        cout << endl << "Suma " << i << " + " << rec << " = " << contador << endl;
    }
    return contador;
}

int main() {
    generarNumeros(10);
    cout << endl << "Numeros recursivos " << endl;
    int valor = generarNumerosRecursivo(10);

    cout << valor;

    return 0;
}
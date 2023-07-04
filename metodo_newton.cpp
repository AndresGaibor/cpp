#include <iostream>
#include <cmath>

using namespace std;

float fn(float x) {
    return pow(2, x) + x - 2;
}

float derivada(float x) {
    return pow(2, x) * log(2) + 1;
}
float fn(float x) {
    return pow(x, 2) + 1;
}

float derivada(float x) {
    return 2 * x * pow(2, x) * log(2) + 1;
}

float fn2(float x) {
    return pow(3, x) + x - 3;
}

float derivada2(float x) {
    return pow(3, x) * log(3) + 1;
}

float metodoNewton(float x0, float tolerancia = 0.001, int contador = 0) {
    float x1 = x0 - fn(x0) / derivada(x0);

    do {
        cout << endl << "Iteracion X" << contador++ << ": " << x1 << endl;
        x0 = x1;
        x1 = x0 - fn(x0) / derivada(x0);
    } while(abs(x1 - x0) > tolerancia);

    return x1;
}

float metodoNewton2(float x0, float tolerancia = 0.001, int contador = 0) {
     float x1 = x0 - fn2(x0) / derivada2(x0);

    do {
        cout << endl << "Iteracion X" << contador++ << ": " << x1 << endl;
        x0 = x1;
        x1 = x0 - fn2(x0) / derivada2(x0);
    } while(abs(x1 - x0) > tolerancia);

    return x1;
}

int main() {
    float x0, tolerancia;

    cout << "Ingrese el valor inicial: ";
    cin >> x0;

    cout << "La raiz es aprox: " << metodoNewton2(x0) << endl;

    return 0;
}
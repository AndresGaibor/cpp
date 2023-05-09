/**
* Generalize: Imprimir la tabla con las raíces cuadradas 
* de los valores comprendidos entre 6.0 y 7.5 con incrementos de 0.001
* Autor: Andres Gaibor
*/

#include <iostream>
#include <cmath>

using namespace std;

int raices(float a, float b, float incremento) {
    if (a > b) {
        return 0;
    }

    cout << a << " " << sqrt(a) << endl;

    return raices(a + incremento, b, incremento);

}

int main() {
    float a, b, incremento;

    cout << "Ingrese el valor inicial: ";
    cin >> a;

    cout << "Ingrese el valor final: ";
    cin >> b;

    cout << "Ingrese el incremento: ";
    cin >> incremento;

    raices(a, b, incremento);

    return 0;
}
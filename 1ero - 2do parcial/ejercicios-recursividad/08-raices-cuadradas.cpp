/**
* Imprimir la tabla con las raíces cuadradas de los valores comprendidos 
* entre 6.0 y 7.5 con incrementos de 0.001
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
    float a = 6.0;
    float b = 7.5;
    float incremento = 0.001;

    raices(a, b, incremento);


    return 0;
}
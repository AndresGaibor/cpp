/**
* Determinar los puntos de coordenadas enteras que están sobre la circunferencia X^2 + Y^2 = 25
* Autor: Andres Gaibor
*/

#include <iostream>
#include <cmath>

using namespace std;

/**
 * Y^2 = r^2 - x^2
 * Y = +/- sqrt(r^2 - x^2)
 * f(x) = +/- sqrt(r^2 - x^2)
*/

void puntosCoordenadas(int d, int x = -1000) {
    int sqrtD = sqrt(d);

    if(x > sqrtD) {
        return;
    }

    if(x == -1000) { // Inicializar a la izquierda
        x = -sqrtD;
    }

    int y = sqrt(d - pow(x, 2));

    cout << endl << "P. coordenada (" << x << "; " << y << ")";
    
    if(y != 0) {
        cout    << endl << "P. coordenada (" << x << "; " << -y << ")";
    }
    
    puntosCoordenadas(d, x + 1);
}


int main() {
    cout << "Los puntos coordenadas de la circunferencia X^2 + Y^2 = r^2";
    int r;
    cout << endl << "Ingrese el valor del radio (r): ";
    cin >> r;
    puntosCoordenadas(r*r);

    return 0;
}
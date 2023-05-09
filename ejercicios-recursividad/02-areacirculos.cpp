/**
 * Generar el área de los círculos cuyo radio está comprendido entre los valores A y B
 * Autor: Andres Gaibor
*/

#include <iostream>
#include <cmath>

using namespace std;

float calcAreaCirc(int radio) {
    return M_PI * radio * radio;
}

float areaCirculos(int rA, int rB, float areaTotal = 0) {
    if(rB + 1 == rA) {
        return areaTotal;
    }

    areaTotal += calcAreaCirc(rA);

    return areaCirculos(rA + 1, rB, areaTotal);
}


int main() {
    int numeroA, numeroB;
    cout << "Ingrese el radio A: ";
    cin >> numeroA;
    cout << "Ingrese el radio B: ";
    cin >> numeroB;

    cout << "El radio de los circulos es de: " << areaCirculos(numeroA, numeroB);



    return 0;
}
/**
 * Definir un TDA Vector
 * Autor: Andres Gaibor
*/

#include <iostream>
#include "../../utilidades/vector.h"

using namespace std;



int main() {
    vector vec;

    vec.setNEl(5);

    cout << endl << "El valor del atributo num. elementos es: " << vec.getNumeroEl();

    return 0;
}
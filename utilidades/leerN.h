#include <iostream>

using namespace std;

#ifndef LEERN_H
#define LEERN_H

int leerN(char mensaje[] = "Ingrese la cantidad de numeros (mayor a 0): ") {
    int n;
    cout << mensaje;
    cin >> n;
    
    if(n < 1) {
        n = leerN();
    }

    return n;
}

#endif
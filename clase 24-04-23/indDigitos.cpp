/**
 * Prog, que permite individualizar los digitos de cada numero
 * Autor: Andres Gaibor
*/

#include <iostream>
using namespace std;

#include "../utilidades/leerN.h"

void individualizarDigitos(int numero, int *dM = 0) {
    if (numero == 0) {
        cout << "> 0" << endl;
        return;
    }

    int dig;

    if(dig != 0) {
        dig = numero % 10;

        if(dig > *dM) {
            *dM = dig;
        }

        int d = numero / 10;
        
        if(d != 0) {
            individualizarDigitos(d, dM);
        }
        cout << endl << "> " << dig << endl;
    }
}

void leerNumeros(int n, int *dMM) {
    n--;

    if(n > 0) {
        leerNumeros(n, dMM);    
    }

    int numero;

    cout << "Numero [" << n << "]: ";
    cin >> numero;

    int dM = 0;

    individualizarDigitos(abs(numero), &dM);

    if(dM > *dMM) {
        *dMM = dM;
    }

    cout << endl << "El digito mayor es " << dM << endl;
}

int main() {
    int n = leerN();

    int dMM = 0;

    leerNumeros(n, &dMM);

    cout << "El digito mas mayor es " << dMM;

    return 0;
}
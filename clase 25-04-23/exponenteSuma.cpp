/**
 * Proma que permita realizar el exponente (A^B) por medio de sumas recursivamente
 * Autor: Andres Gaibor
*/

#include <iostream>

using namespace std;

#include "../utilidades/leerN.h"

int exponencialC(int a, int b) {
    int c = 1;
    for(int i = 1; i <= b; i++) {
        int contador = c;
        for(int j = 1; j < a; j++) {
            contador += c;
        }

        c = contador;
    }

    return c;
}

int multiplicacion(int a, int b) {
    if (b == 0) {
        return 0;
    }
    
    return a + multiplicacion(a, b - 1);
}

int exponencial(int a, int b, int c = 0) {
    if(b == 1) {
        return c;
    }

    if(c == 0) {
        c = a;
    }

    c = multiplicacion(a, c);

    return exponencial(a, b - 1, c);
}



int main() {
    int a, b;

    char pregunta[] = "Ingrese el numero base A (mayor a 0): ";
    char pregunta2[] = "Ingrese el numero exponente B (mayor a 0): ";

    a = leerN(pregunta); b = leerN(pregunta2);

    int expo2 = exponencial(a, b);

    cout << "El exponencia (" << a << "^" << b << ") es: " << expo2;    
}

/**
     * 3^2 = 9; (3 veces)
     *      3 + 3 + 3
     * A = 2 Y B = 5
     * 
     *      2^5 = 32; 2 * 2 * 2 * 2 * 2 - SE REALIZA N (B) VECES
     * C = 1;   (C0 + C1 + ... + CN(A) )
     * B1 2 (1 + 1)
     * C = 2;   (C0 + C1 + ... + CN(A) )
     * B2 4  (2 + 2)
     * C = 4;   (C0 + C1 + ... + CN(A) )
     * B3 8 (4 + 4)
     * C = 8;   (C0 + C1 + ... + CN(A) )
     * B4 16 (8 + 8)
     * C = 16;   (C0 + C1 + ... + CN(A) )
     * B5 32 (16 + 16)
     * 
     * 
     * A = 3 Y B = 4
     * 
     *      3^4 = 81; 3*3*3*3 - SE REALIZA N (B) VECES
     * C = 1;   (C0 + C1 + ... + CN(A) )
     * B1 2 (1 + 1 + 1)
     * C = 3;   (C0 + C1 + ... + CN(A) )
     * B2 3  (3 + 3 + 3)
     * C = 9;   (C0 + C1 + ... + CN(A) )
     * B3 27 (9 + 9 + 9)
     * C = 27;   (C0 + C1 + ... + CN(A) )
     * B4 81 (27 + 27 + 27)
     * 
     *  
     * 4^2 = 16; (4 veces) A * (B-1)
     *      4 + 4 + 4 + 4;
     * 4^3 = 32; (8 veces) A * (B-1)
     *      4 + 4 + 4 + 4 + 4 + 4 + 4 + 4
    */
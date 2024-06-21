// Estudiante: Andres Gaibor 7255

#include <iostream>
using namespace std;

int division(int a, int b) {
    int resultado = 0;

    if(b > a) {
        cout << "El dividendo debe ser mayor que el divisor" << endl;
        return -1;
    }

    while(a >= b) {
        a = a - b;

        resultado++;
    }

    return resultado;
}

double multiplicarSuma(int num, int veces) {
    if(veces == 0 ){
        return 0;
    }

    return multiplicarSuma(num, veces - 1) + num;
}

double calcula_decimales(int a, int b) {
    if(a < b) {
        a = multiplicarSuma(a, 100);  
    }
    
    return division(a, b);
}

int division_recursiva(int a, int b, int *residuo) {
    if(b > a) {
        *residuo = calcula_decimales(a, b);
        return 0;
    }

    return division_recursiva(a - b, b, residuo) + 1;
}

int main() {
    int a, b;
    cout << "Ingrese el dividendo: ";
    cin >> a;

    cout << "Ingrese el divisor: ";
    cin >> b;

    int residuo = 0;

    cout << "El cociente es " << division_recursiva(a, b, &residuo) << endl;
    cout << "El residuo es " << residuo << endl << endl;
}
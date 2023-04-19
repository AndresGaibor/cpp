/**
 * Programa que analiza si una cadena un palindromo
 * Autor: Andres Gaibor
*/

#include <iostream>
#include "string.h"

using namespace std;

int leerN() {
    int n;
    cout << "Ingrese el numero de caracteres: ";
    cin >> n;

    cin.ignore();

    return n;
}

void leerCadena(char frase[], int n) {
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(frase, n, '\n');
    cin.ignore();
    fflush(stdin);
}

bool esPalindromo(char frase[], int n, int i = 0) { // oso -> n = 3 [0] == [2]
    bool resultado = true;

    if(frase[i] != frase[n - 1 - i]) {
        return false;
    }
    // abcda 7 - 6 - 3 
    if(i + 1 < n/2) {
        i++;
        resultado = esPalindromo(frase, n, i);
    }

    return resultado;
}

// el buffer es la memoria intermedia entre el teclado y el computador
int main() {
    int n = leerN();
    char frase[n];

    leerCadena(frase, n);
    
    cout << endl << "La cadena ingresada es: " << frase << endl;

    int cantCar = strlen(frase);

    cout << "long " << cantCar << endl; 

    bool pal = esPalindromo(frase, cantCar);

    if(pal) {
        cout << "La frase es palindromo ";
    } else {
        cout << "La frase no es palindromo ";
    }
    


    return 0;
}
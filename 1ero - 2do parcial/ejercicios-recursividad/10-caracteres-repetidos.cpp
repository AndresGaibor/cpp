/**
* Determinar las letras más repetidas encontradas en una cadena ingresada (evitar repeticiones)
* Autor: Andres Gaibor
*/

#include <iostream>
#include <string.h>

using namespace std;

bool esLetra(char letra) {
    return (letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z');
}

char letrasRepetidasCiclos(char cadena[]) {
    int longitud = strlen(cadena);

    char letraMasRepetida;
    int vecesMasRepetida = 0;

    for(int i = 0; i < longitud; i++) {
        char letra = cadena[i];
        int veces = 0;

        if(!esLetra(letra)) {   continue;   }

        for(int j = i; j < longitud; j++) {
            if(letra == cadena[j]) {
                veces++;
            }
        }

        if(veces > vecesMasRepetida) {
            vecesMasRepetida = veces;
            letraMasRepetida = letra;
        }
    }

    return letraMasRepetida;
}

int contarLetra(char cadena[], char letra, int longitud, int i = 0, int veces = 0) {
    if(i == longitud) {
        return veces;
    }

    if(cadena[i] == letra) {
        veces++;
    }

    return contarLetra(cadena, letra, longitud, i + 1, veces);
}

char letrasRepetidas(char cadena[], int longitud, char letraMasRepetida = ' ', int vecesMasRepetida = 0, int i = 0) {
    if(i == longitud) {
        return letraMasRepetida;
    }

    char letra = cadena[i];

    if(!esLetra(letra)) {
        return letrasRepetidas(cadena, longitud, letraMasRepetida, vecesMasRepetida, i + 1);
    }

    int veces = contarLetra(cadena, letra, longitud, i);

    if(veces > vecesMasRepetida) {
        vecesMasRepetida = veces;
        letraMasRepetida = letra;
    }

    return letrasRepetidas(cadena, longitud, letraMasRepetida, vecesMasRepetida, i + 1);
}


int main() {
    char cadena[100]; 

    cout << "Ingresar cadena: ";
    cin.getline(cadena, 100, '\n');

    int longitud = strlen(cadena);
    cout << "La letra que mas se repite es: " << letrasRepetidas(cadena, longitud) << endl;

    return 0;
}
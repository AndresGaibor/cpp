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

int longitudString(char palabra[]) {
    return strlen(palabra);
}

bool esLetra(char letra) {
    return ((letra >= 'A' && letra <= 'Z')  || (letra >= 'a' && letra <= 'z'));
}

int splitPalabras(char cadena[], char palabras[][100], int nCadena, int nPalabras = 0, int i = 0, int colum = 0) {
    if(esLetra(cadena[i])) {
        palabras[nPalabras][colum] = cadena[i];
        colum++;
    } else {
        colum = 0;

        if(esLetra(cadena[i+1])) {
            nPalabras++;
        }
    }

    if(i < nCadena) {
        i++;
        return splitPalabras(cadena, palabras, nCadena, nPalabras, i, colum);
    }

    return nPalabras;
}

bool esPalindromo(char palabra[], int n, int i = 0) { // oso -> n = 3 [0] == [2]
    bool resultado = true;

    if(palabra[i] != palabra[n - 1 - i]) {
        return false;
    }
    // abcda 7 - 6 - 3 
    if(i + 1 < n/2) {
        i++;
        resultado = esPalindromo(palabra, n, i);
    }

    return resultado;
}

// el buffer es la memoria intermedia entre el teclado y el computador
int main() {
    int n = 100; //leerN();
    char frase[n];
    char palabras[100][100];

    leerCadena(frase, n);
    
    cout << endl << "La cadena ingresada es: " << frase << endl;

    int cantCar = strlen(frase);

    cout << "long " << cantCar << endl; 

    int cantPal = splitPalabras(frase, palabras, cantCar);

    cout << endl << "Cantidad de palabra: " << cantPal;

    for(int i = 0; i <= cantPal; i++) {
        // char palabra[] = palabras[i];
        cout << endl << "La palabra '" << palabras[i] << "' ";

        int longPalabra = longitudString(palabras[i]);

        bool pal = esPalindromo(palabras[i], longPalabra);

        cout << (pal ? "" : "no") << " es palindromo" << endl;
    }

    return 0;
}
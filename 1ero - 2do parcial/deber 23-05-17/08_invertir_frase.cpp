/**
* Ingresar una frase y proceda a invertir el orden de las palabras, por medio del empleo de pilas
* Autor: Andres Gaibor
*/

#include <iostream>

typedef char Tipo;

#include "../../utilidades/pila.h"


using namespace std;

string fraseInversa(string frase) {
    Pila p;
    char palabra;
    string fraseInversa = "";

    for(int i = 0; i < frase.length(); i++) {
        p.push(frase[i]);
    }

    while(!p.isEmpty()) {
        palabra = p.pop();
        fraseInversa += palabra;
    }

    return fraseInversa;
}

int main() {
    string frase;

    cout << "Ingrese una frase: ";
    getline(cin, frase);

    cout << endl << "La frase invertida es: " << fraseInversa(frase);

    return 0;
}
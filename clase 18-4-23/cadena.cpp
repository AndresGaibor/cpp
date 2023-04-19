/**
 * Programa de gestion de cadenas
 * Autor: Andres Gaibor
*/

#include <iostream>
#include <string>

using namespace std;

int leerN() {
    cout << "";

    return 0;
}

void leerCaracter() {

}
// el buffer es la memoria intermedia entre el teclado y el computador
int main() {
    char frase[15];

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(frase, 15, '\n');
    fflush(stdin);
    
    cout << endl << "La cadena ingresada es: " << frase << endl;


    return 0;
}
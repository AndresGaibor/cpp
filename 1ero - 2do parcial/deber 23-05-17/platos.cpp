/**
* Encontrar el máximo y mínimo elemento de una pila
* Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/pila.h"

using namespace std;

void lavarPlato(int cantidad, Pila *platosSucio, Pila *platosLimpio) {
    if(cantidad == 0 || platosSucio->isEmpty()) {
        return;
    }
    
    int plato = platosSucio->pop();
    platosLimpio->push(plato);

    lavarPlato(cantidad - 1, platosSucio, platosLimpio);
}

void inicializarPlatosSucios(int cantidad, Pila *p) {
    for(int i = 0; i < cantidad; i++) {
        p->push(1);
    }
}  

int main() {
    Pila platosLimpio, platosSucio;

    int cantidadPlatosSucios = 0;

    cout << "Ingrese la cantidad de platos sucios: ";
    cin >> cantidadPlatosSucios;

    inicializarPlatosSucios(cantidadPlatosSucios, &platosSucio);

    int cantidadPlatosALavar = 0;

    cout << "Ingrese la cantidad de platos a lavar: ";
    cin >> cantidadPlatosALavar;

    lavarPlato(cantidadPlatosALavar, &platosSucio, &platosLimpio);

    cout << endl << "Platos limpios: " << platosLimpio.longitudPila();
    cout << endl << "Platos sucios: " << platosSucio.longitudPila();

    cout << endl << endl;

    return 0;
}
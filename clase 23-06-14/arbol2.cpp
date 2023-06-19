/**
 * 
 * Autor: Andres Gaibor
*/

#include <iostream>
#include "../utilidades/nodoArbol.h"

#define MAX 20
#define FIN 99999

using namespace std;

void ingresarNumerosEnLista(NodoBinario nod[], int *cant, NodoBinario *padre = nullptr)
{
    int valor, op;

    cout << "Ingrese un numero (SALGA CON " << FIN << " ): ";
    cin >> valor;

    cout << "Desea ingresar hijo izquierdo (Ingrese 1) o hijo derecho (Ingrese 2): ";
    cin >> op;
    // 7182 7.03 93.94
    // mi nota 8.84 90.91

    if(valor == FIN) {
        return;
    }

    nod[*cant].setDato(valor);

    (*cant)++;

    ingresarNumerosEnLista(nod, cant, padre);
}

int main() {
    NodoBinario nodos[MAX];

    NodoBinario n1, n2, n3, n4, n5;

    n1 = NodoBinario(100, &n2, &n3); // Padre

    n2 = NodoBinario(25, &n4, &n5);
    n3.setDato(38);

    n4.setDato(45); // hojas
    n5.setDato(50);
    
    cout << endl << "valor almacenado en el nodo n4 (hijo izq) " << n4.getDato();
    cout << endl << "valor almacenado en el nodo 2 (padre n4) " << n4.getPadre()->getDato();
    cout << endl << "valor almacenado en el nodo 1 (padre n2) " << n4.getPadre()->getPadre()->getDato();

    cout << endl;
    
    return 0;
}
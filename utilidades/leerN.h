// #include <iostream>

// using namespace std;

#ifndef LEERN_H
#define LEERN_H

#include "lista.h"

void ingresarNumerosEnLista(int FIN, Lista *lista, char mensaje[] = "Ingrese un numero")
{
    int valor;

    cout << mensaje << " (SALGA CON " << FIN << " )" << endl;
    cin >> valor;

    if(valor == FIN) {
        return;
    }

    lista->insertarFinal(valor);

    ingresarNumerosEnLista(FIN, lista, mensaje);
}

#endif
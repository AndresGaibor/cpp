/**
 * Solicitud y respuestas de llamadas de un CallCenter de servicio al cliente
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "utilidades/cola.h"

using namespace std;

void llamar(Cola *c) // Cada cliente realiza una llamada
{
    int numero;

    cout << "Ingrese tu numero de telefono: ";
    cin >> numero;

    c->enqueue(numero);
}

void llamadasDeClientes(Cola *c)
{
    int cantidad;

    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        cout << endl
             << endl
             << "Cliente " << i + 1 << endl;
        llamar(c);
    }
}

void contestarOperador(Cola *c)
{
    if (c->isEmpty())
    {
        return;
    }

    int numero = c->dequeue();

    cout << endl
         << "Contestando llamada del numero " << numero << " ...";

    contestarOperador(c);
}

int main()
{
    Cola llamadas;

    llamadasDeClientes(&llamadas);

    contestarOperador(&llamadas);

    return 0;
}
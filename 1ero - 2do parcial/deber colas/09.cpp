/**
 * Calcular la diferencia existente entre el N-ésimo
 * elemento de una cola, y los valores precedentes a este
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>
#include "../utilidades/colaCircular.h"

using namespace std;

int calcularDiferencia(ColaCircular cola, int n)
{
    int contador = 0;
    Tipo predecesores = 0, valorN = 0, dif;

    while (!cola.isEmpty() && contador < n)
    {
        predecesores += cola.dequeue();

        contador++;
    }
    if (!cola.isEmpty())
    {
        valorN = cola.dequeue();
    }

    dif = predecesores - valorN;

    return (dif > 0 ? dif : dif * -1);
}

int main()
{
    ColaCircular cola;

    cola.leer();

    cout << "Ingrese el valor de N: ";
    int n;
    cin >> n;

    cout << "Diferencia: " << calcularDiferencia(cola, n) << endl;

    return 0;
}
/**
 * Calcular la desviación típica existente entre los valores
 * pertenecientes a una cola de valores ingresados
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef float Tipo;

#include <iostream>
#include <math.h>
#include "../utilidades/colaCircular.h"

using namespace std;

float calcularMedia(ColaCircular cola)
{
    float media = 0;
    int contador = 0;
    Tipo valor;

    while (!cola.isEmpty())
    {
        valor = cola.dequeue();
        media += valor;
        contador++;
    }

    return media / contador;
}

float calcularDesviacion(ColaCircular cola)
{
    float media = calcularMedia(cola);
    float desviacion = 0;
    Tipo valor;

    while (!cola.isEmpty())
    {
        valor = cola.dequeue();
        desviacion += pow(valor - media, 2);
    }

    return sqrt(desviacion / cola.size());
}

int main()
{
    ColaCircular cola;

    cola.leer();

    cout << "Desviacion tipica: " << calcularDesviacion(cola) << endl;

    return 0;
}
/**
 * Permitir el ingreso de varios números enteros,
 * y generar una cola ordenada con los divisores primos de cada uno de ellos
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef int Tipo;

#include <iostream>
#include "../../utilidades/colaCircular.h"

using namespace std;

int datoDesdeEntrada(string mensaje = "Ingresar un dato")
{
    string linea;
    cout << endl
         << mensaje << " (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return NULL;
    }

    int dato = stoi(linea);

    return dato;
}

bool esPrimo(int n)
{
    int contador = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            contador++;
        }
    }

    return contador == 2;
}

void generarCola(ColaCircular *cola, Tipo valor)
{

    for (int i = 1; i <= valor; i++)
    {
        if (valor % i == 0 && esPrimo(i))
        {
            cola->enqueue(i);
        }
    }
}

void leerNumero(ColaCircular *cola)
{
    int dato = datoDesdeEntrada();

    if (dato == NULL)
    {
        return;
    }

    generarCola(cola, dato);

    leerNumero(cola);
}

int main()
{
    ColaCircular cola;

    leerNumero(&cola);

    cola.mostrar(cola);

    return 0;
}
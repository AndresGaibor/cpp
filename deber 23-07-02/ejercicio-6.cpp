/**
 * Permitir el ingreso de N valores por parte del usuario,
 * y proceder a generar todos los ABB posibles construidos a partir de los mismos.
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/arbolBinario.h"

using namespace std;

void generarABBs(int valores[], int inicio, int fin, NodoBinario *resultados[])
{
    if (inicio > fin)
    {
        resultados[0] = nullptr;
        return;
    }

    int numResultados = 0;

    for (int i = inicio; i <= fin; i++)
    {
        NodoBinario *subarbolesIzq[100];
        NodoBinario *subarbolesDer[100];

        generarABBs(valores, inicio, i - 1, subarbolesIzq);
        generarABBs(valores, i + 1, fin, subarbolesDer);

        for (int j = 0; j <= i - inicio; j++)
        {
            for (int k = 0; k <= fin - i - 1; k++)
            {
                NodoBinario *nuevoNodo = new NodoBinario(valores[i]);
                nuevoNodo->setHijoIzquierdo(subarbolesIzq[j]);
                nuevoNodo->setHijoDerecho(subarbolesDer[k]);
                resultados[numResultados++] = nuevoNodo;
            }
        }
    }

    resultados[numResultados] = nullptr;
}

void generarTodosABBs(int valores[], int N)
{
    NodoBinario *resultados[1000];
    generarABBs(valores, 0, N - 1, resultados);

    cout << "Todos los ABB posibles generados a partir de los valores ingresados:" << endl;

    for (int i = 0; resultados[i] != nullptr; i++)
    {
        ArbolBinario abb;
        abb.setRaiz(resultados[i]);
        abb.recorrerEnInorden();
        cout << endl;
    }

    for (int i = 0; resultados[i] != nullptr; i++)
    {
        delete resultados[i];
    }
}

int main()
{
    int N;
    cout << "Ingrese la cantidad de valores: ";
    cin >> N;

    int valores[100];

    cout << "Ingrese los valores separados por espacios: ";
    for (int i = 0; i < N; i++)
    {
        cin >> valores[i];
    }

    generarTodosABBs(valores, N);

    return 0;
}
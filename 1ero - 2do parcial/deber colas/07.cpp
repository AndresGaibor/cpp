/**
 * Ingresar una cola de valores, y si hubieran valores consecutivos
 * adyacentes en esta, separarlos con un valor correspondiente al
 * promedio calculado entre los dos elementos contiguos al espacio
 * en que se insertará el nuevo valor
 * Autor: Andres Gaibor
 */

#define EXT 100
typedef float Tipo;

#include <iostream>
#include "../utilidades/colaCircular.h"

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

void separarPorPromedio(ColaCircular *c)
{
    ColaCircular aux; // 1, 2 (anterior) ,[promedio del anterior  y sg], (siguiente), 3, 4
    Tipo a = -10000, b, promedio;

    while (!c->isEmpty())
    {
        b = c->dequeue();

        if (b == a + 1)
        {
            promedio = (a + b) / 2;

            aux.enqueue(promedio);
        }

        aux.enqueue(b);

        a = b;
    }
    *c = aux;
}

void leerCola(ColaCircular *cola)
{
    int dato = datoDesdeEntrada();

    if (dato == NULL)
    {
        return;
    }

    cola->enqueueOrdered(dato);

    leerCola(cola);
}

int main()
{
    ColaCircular c;

    leerCola(&c);

    cout << "Cola original: " << endl;
    c.mostrar(c);

    separarPorPromedio(&c);

    cout << "Cola separada: " << endl;
    c.mostrar(c);

    return 0;
}
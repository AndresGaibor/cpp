/**
 * Comprobar si un numero es capicua
 * Autor: Andres Gaibor
 */

#include <iostream>
#include "../utilidades/colaCircular.h"

using namespace std;


void individualizarDigitos(int numero, ColaCircular *c) {
    if (numero == 0) {
        return;
    }

    int dig = numero % 10;

    int d = numero / 10;

    numero = (numero - dig) / 10;

    c->enqueue(dig);
        
    individualizarDigitos(numero, c);
}

int lastValue(ColaCircular c)
{
    int b;

    while (c.CanDequeue())
    {
        b = c.dequeue();
    }

    return b;
}

bool esCapicua(ColaCircular c, int size)
{
    if (c.isEmpty() && c.size() == size/2) {
        return true;
    }

    int first = c.dequeue();

    int last = c.isEmpty() ? first : lastValue(c);

    cout << endl << "primer valor " << first << " " << last;

    if (first != last)
    {
        return false;
    }

    return esCapicua(c, size);
}

void extraerNumero(ColaCircular c) {
    if(c.isEmpty()) {
        return;
    }

    int numero = c.dequeue();

    ColaCircular digitos;
    individualizarDigitos(numero, &digitos);

    digitos.mostrar();

    cout << endl << numero << " " << (esCapicua(digitos, digitos.size()) ? "es" : "no es") << " capicua";

    extraerNumero(c);
}

int main()
{
    ColaCircular c;
    c.leer();

    extraerNumero(c);

    return 0;
}
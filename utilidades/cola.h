#include <iostream>

using namespace std;

#include "vector.h"

class Cola
{
private:
    int frente, final, longitud = EXT;

protected:
    Vector vec;
    void setFrente(int v);
    void setFinal(int v);

    void clean();

public:
    Cola();

    int getFrente();
    int getFinal();

    int getLongitud();

    bool isEmpty();
    bool isFull();
    int size();

    bool enqueue(Tipo v);

    bool CanDequeue();
    Tipo dequeue();

    bool buscar(Cola c, Tipo v);

    void leer();
    void mostrarCola(Cola p);
    void mostrar();
};

Cola::Cola()
{
    setFrente(0);
    setFinal(-1);
}

int Cola::getLongitud()
{
    return longitud;
}

void Cola::setFrente(int v)
{
    frente = v;
}

void Cola::setFinal(int v)
{
    final = v;
}

int Cola::getFrente()
{
    return frente;
}

int Cola::getFinal()
{
    return final;
}

bool Cola::isEmpty()
{
    return getFinal() < getFrente();
}

bool Cola::isFull()
{
    return size() == EXT - 1;
}

int Cola::size()
{
    return (getFinal() - getFrente() + 1);
}

bool Cola::enqueue(Tipo v)
{
    if (isFull())
    {
        cout << endl
             << "La cola esta llena" << endl;
        return false;
    }
    int final = getFinal() + 1;

    setFinal(final);

    vec.setVector(final, v);

    return true;
}

void Cola::clean()
{
    setFinal(-1);
    setFrente(0);
}

bool Cola::CanDequeue()
{
    return isEmpty() == false;
}

Tipo Cola::dequeue()
{
    if (CanDequeue() == false)
    {
        return -10000000;
    }

    Tipo value = vec.getVector(getFrente());

    if (getFrente() == getFinal())
    {
        clean();
    }
    else
    {
        setFrente(getFrente() + 1);
    }

    return value;
}

bool Cola::buscar(Cola c, Tipo v)
{
    if (c.isEmpty())
    {
        return false;
    }

    if (c.dequeue() == v)
    {
        return true;
    }

    return buscar(c, v);
}

void Cola::leer()
{
    if (isFull())
    {
        cout << endl
             << "La cola esta llena";
        return;
    }

    string linea;
    cout << endl
         << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return;
    }

    int dato = stoi(linea);
    enqueue(dato);

    leer();
}

void Cola::mostrarCola(Cola c)
{
    if (c.isEmpty())
    {
        return;
    }

    if (!c.isEmpty())
    {
        cout << endl
             << "Elemento [" << c.getFinal() << "]: " << c.dequeue();
    }
    else
    {
        cout << endl
             << "No se puede desencolar (cola vacia)";
    }

    mostrarCola(c);
}

void Cola::mostrar()
{
    mostrarCola(*this);
}
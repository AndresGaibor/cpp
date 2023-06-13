
#ifndef COLACIRCULAR_H

#include "cola.h"

class ColaCircular : public Cola
{
private:
    int gap;

public:
    ColaCircular();
    // void setGap(int v);
    // int getGap();
    // int getFinal();
    // int getFrente();
    bool isFull();
    // bool isEmpty();
    // void next();
    void leer();
    void leerChar();
    void mostrar(ColaCircular c);
    void enqueueOrdered(Tipo v);
    bool enqueue(Tipo v);
    Tipo dequeue();
};

ColaCircular::ColaCircular() : Cola()
{
}

bool ColaCircular::enqueue(Tipo v)
{
    if (isFull())
    {
        cout << endl
             << "La cola está llena";
        return false;
    }

    // int final = (getFinal() + 1) % getLongitud();
    int final = getFinal() + 1;

    setFinal(final);

    vec.setVector(final, v);

    return true;
}

Tipo ColaCircular::dequeue()
{
    if (CanDequeue() == false)
    {
        return -10000000;
    }

    Tipo value = vec.getVector(getFrente() % getLongitud());

    if (getFrente() == getFinal())
    {
        clean();
    }
    else
    {
        setFrente((getFrente() + 1) % getLongitud());
    }

    return value;
}

void ColaCircular::leer()
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

void ColaCircular::leerChar()
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

    enqueue(linea.at(0));

    leer();
}

void ColaCircular::mostrar(ColaCircular c)
{

    if (c.isEmpty())
    {
        return;
    }

    cout << c.dequeue() << " ";

    mostrar(c);
}

void ColaCircular::enqueueOrdered(Tipo v)
{
    if (isFull())
    {
        cout << endl
             << "La cola está llena";
        return;
    }

    if (isEmpty() || v >= vec.getVector(getFinal() % getLongitud()))
    {
        enqueue(v);
        return;
    }

    Cola temp;

    while (!isEmpty() && v < vec.getVector(getFinal() % getLongitud()))
    {
        Tipo value = dequeue();
        temp.enqueue(value);
    }

    enqueue(v);

    while (!temp.isEmpty())
    {
        Tipo value = temp.dequeue();
        enqueue(value);
    }
}

// ColaCircular::ColaCircular() : Cola()
// {
//     setGap(getLongitud() - 1);
// }

// void ColaCircular::setGap(int v)
// {
//     gap = v;
// }

// int ColaCircular::getGap()
// {
//     return gap;
// }

// int ColaCircular::getFinal()
// {
//     return Cola::getFinal() % Cola::getLongitud();
// }

bool ColaCircular::isFull()
{
    return (getLongitud() - 1) == Cola::getFinal() - Cola::getFrente();
}

// bool ColaCircular::isEmpty()
// {
//     return Cola::isEmpty();
// }

// // 0, 1, 2 -- longitud 3, gap 2, final 2, frente 0
// // -, 1, 2 -- longitud 3, gap 2, final 2, frente 1
// // -, -, 2 -- longitud 3, gap 2, final 2, frente 2
// // 4, -, 2 -- longitud 3, gap 2, final 2, frente 2
// // 4, -, - -- longitud 3, gap 2, final 2, frente 3 -- frentre = gap + 1

// // gap 2 == final - frente; true esta full

// void ColaCircular::next()
// {
//     if (isFull())
//     {
//         return;
//     }

//     int final = Cola::getFinal() + 1;

//     Cola::setFinal(final % Cola::getLongitud());
// }

// int ColaCircular::getFrente()
// {
//     return Cola::getFrente() % Cola::getLongitud();
// }

// bool ColaCircular::enqueue(Tipo v)
// {
//     if (isFull())
//     {
//         cout << endl
//              << "La cola circular está llena";
//         return false;
//     }

//     next();

//     vec.setVector(getFinal(), v);

//     setFinal(getFinal() + 1); // Actualizar el valor de final

//     return true;
// }

// Tipo ColaCircular::dequeue()
// {
//     if (isEmpty())
//     {
//         cout << endl
//              << "La cola circular está vacía";
//         return -1; // Valor sentinela para indicar un error
//     }

//     Tipo v = vec.getVector(getFrente());

//     setFrente(getFrente() + 1);
//     setFinal(getFinal() - 1); // Actualizar el valor de final

//     return v;
// }

#endif